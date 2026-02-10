
--ตาราง log
CREATE TABLE booking_changelog (
    log_id BIGSERIAL PRIMARY KEY,
    booking_id BIGINT,
    action_type VARCHAR(20), -- VIEW / EDIT / DELETE
    performed_by INT,        -- user_id
    performed_at TIMESTAMP DEFAULT NOW()
);

-------------------------------- VIEW --------------------------------

CREATE OR REPLACE FUNCTION view_booking(
    p_booking_id BIGINT,
    p_user_id INT
)
RETURNS TABLE (
    booking_id BIGINT,
    patient_id INT,
    dentist_id INT,
    shop_id SMALLINT,
    status booking_status,
    appointment_date DATE,
    start_time TIME,
    end_time TIME
)
LANGUAGE plpgsql
AS $$
BEGIN
    -- 1. permission check
    IF NOT EXISTS (
        SELECT 1
        FROM booking b
        JOIN app_user u ON u.user_id = p_user_id
        WHERE b.booking_id = p_booking_id
          AND (u.admin_flag = TRUE OR b.patient_id = p_user_id)
    ) THEN
        RAISE EXCEPTION 'Permission denied';
    END IF;

    -- 2. LOG
    INSERT INTO booking_changelog (booking_id, action_type, performed_by)
    VALUES (p_booking_id, 'VIEW', p_user_id);

    -- 3. return data
    RETURN QUERY
    SELECT 
        b.booking_id,
        b.patient_id,
        b.dentist_id,
        b.shop_id,
        b.status,
        b.appointment_date,
        b.start_time,
        b.end_time
    FROM booking b
    WHERE b.booking_id = p_booking_id;
END;
$$;


-------------------------------- EDIT --------------------------------

CREATE OR REPLACE FUNCTION edit_booking_time(
    p_booking_id BIGINT,
    p_user_id INT,
    p_new_date DATE,
    p_new_start TIME,
    p_new_end TIME
)
RETURNS VOID
LANGUAGE plpgsql
AS $$
DECLARE
    v_status booking_status;
BEGIN
    -- 1. permission check
    IF NOT EXISTS (
        SELECT 1
        FROM booking b
        JOIN app_user u ON u.user_id = p_user_id
        WHERE b.booking_id = p_booking_id
          AND (u.admin_flag = TRUE OR b.patient_id = p_user_id)
    ) THEN
        RAISE EXCEPTION 'Permission denied';
    END IF;

    --
    IF p_new_start >= p_new_end THEN
    RAISE EXCEPTION 'Invalid time range';
    END IF;

    --
    IF EXISTS (
        SELECT 1
        FROM booking b
        WHERE b.booking_id <> p_booking_id
        AND b.dentist_id = (SELECT dentist_id FROM booking WHERE booking_id = p_booking_id)
        AND b.shop_id = (SELECT shop_id FROM booking WHERE booking_id = p_booking_id)
        AND b.appointment_date = p_new_date
        AND b.status = 'Active'
        AND NOT (p_new_end <= b.start_time OR p_new_start >= b.end_time)
    ) THEN
        RAISE EXCEPTION 'Time slot is not available';
    END IF;

    -- 2. check current status
    SELECT status
    INTO v_status
    FROM booking
    WHERE booking_id = p_booking_id;

    IF v_status IN ('Cancelled', 'Completed') THEN
        RAISE EXCEPTION 'Cannot edit booking with status %', v_status;
    END IF;

    -- 3. update booking
    UPDATE booking
    SET appointment_date = p_new_date,
        start_time = p_new_start,
        end_time = p_new_end
    WHERE booking_id = p_booking_id;

    -- 4. log
    INSERT INTO booking_changelog (booking_id, action_type, performed_by)
    VALUES (p_booking_id, 'EDIT', p_user_id);
END;
$$;

-------------------------------- DELETE (Cancel a Booking) --------------------------------

CREATE OR REPLACE FUNCTION delete_booking(
    p_booking_id BIGINT,
    p_user_id INT
)
RETURNS VOID
LANGUAGE plpgsql
AS $$
DECLARE
    v_current_status booking_status;
    v_patient_id INT;
    v_is_admin BOOLEAN;
BEGIN
    -- 1. GET BOOKING INFO
    SELECT status, patient_id 
    INTO v_current_status, v_patient_id
    FROM booking
    WHERE booking_id = p_booking_id;

    -- If no row found, the booking doesn't exist
    IF NOT FOUND THEN
        RAISE EXCEPTION 'Booking ID % not found.', p_booking_id;
    END IF;

    -- 2. CHECK PERMISSIONS
    SELECT admin_flag INTO v_is_admin
    FROM app_user
    WHERE user_id = p_user_id;

    -- Allow if: User is Admin OR User is the Patient who owns the booking
    IF (v_is_admin IS FALSE) AND (v_patient_id != p_user_id) THEN
        RAISE EXCEPTION 'Permission denied: You cannot cancel this booking.';
    END IF;

    -- Completed -> Cancelled (FORBIDDEN)
    IF v_current_status = 'Completed' THEN
        RAISE EXCEPTION 'Cannot cancel a booking that is already Completed.';
    END IF;

    -- Cancelled -> Cancelled (REDUNDANT)
    IF v_current_status = 'Cancelled' THEN
        RAISE NOTICE 'Booking is already cancelled. No action taken.';
        RETURN; -- Exit the function, do nothing
    END IF;

    UPDATE booking
    SET status = 'Cancelled'
    WHERE booking_id = p_booking_id;

    -- log
    INSERT INTO booking_changelog (booking_id, action_type, performed_by)
    VALUES (p_booking_id, 'DELETE', p_user_id);
END;
$$;
