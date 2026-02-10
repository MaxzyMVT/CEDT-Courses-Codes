CREATE OR REPLACE FUNCTION book_appointment(
    p_patient_id INT,
    p_dentist_id INT,
    p_shop_id SMALLINT,
    p_appointment_date DATE,
    p_start_time TIME,
    p_service_id SMALLINT[]
)
RETURNS BIGINT AS $$
DECLARE
    total_minutes INT;
    v_end_time TIME;
    v_booking_id BIGINT;
BEGIN
   	--LOGGIN ?
    IF NOT EXISTS (
        SELECT 1
        FROM user_status
        WHERE user_id = p_patient_id
        AND is_active = TRUE
    ) THEN
        RAISE EXCEPTION 'User must be logged in.';
    END IF;

	--TOTAL MIN
    SELECT SUM(max_duration_minutes)
    INTO total_minutes
    FROM service
    WHERE service_id = ANY(p_service_id);

    IF total_minutes IS NULL THEN
        RAISE EXCEPTION 'Invalid service selection.';
    END IF;

    v_end_time := p_start_time + ((total_minutes || ' minutes')::INTERVAL);

    --BOOKING SAME TIME
    IF EXISTS (
        SELECT 1
        FROM booking
        WHERE dentist_id = p_dentist_id
          AND appointment_date = p_appointment_date
          AND status = 'Active'
          AND (
              p_start_time < end_time
              AND v_end_time > start_time
          )
    ) THEN
        RAISE EXCEPTION 'Booking time overlaps with existing booking.';
    END IF;

    -- INSERT BOOKING
    INSERT INTO booking(
        patient_id,
        dentist_id,
        shop_id,
        status,
        appointment_date,
        start_time,
        end_time
    )
    VALUES (
        p_patient_id,
        p_dentist_id,
        p_shop_id,
        'Active',
        p_appointment_date,
        p_start_time,
        v_end_time
    )
    RETURNING booking_id INTO v_booking_id;

    -- Insert booked services
    INSERT INTO books_service(booking_id, service_id)
    SELECT v_booking_id, unnest(p_service_id);

    RETURN v_booking_id;
END; $$ LANGUAGE plpgsql;

CREATE TABLE booking_status_log (
    log_id BIGINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    booking_id BIGINT,
    action VARCHAR(20),
    log_time TIMESTAMP DEFAULT NOW()
);




-- ==================== Function to mark a booking as Completed ============================

CREATE OR REPLACE FUNCTION complete_booking(
    p_booking_id BIGINT
)
RETURNS VOID 
LANGUAGE plpgsql AS $$
BEGIN
    -- 1. Check if the booking exists and is currently Active
    IF NOT EXISTS (
        SELECT 1 
        FROM booking 
        WHERE booking_id = p_booking_id 
        AND status = 'Active'
    ) THEN
        RAISE EXCEPTION 'Booking not found or is not currently active.';
    END IF;

    -- 2. Update the status to 'Completed'
    UPDATE booking
    SET status = 'Completed'
    WHERE booking_id = p_booking_id;
    
END;
$$;

-- ==================== Booking Status Change Triggers ============================

CREATE OR REPLACE FUNCTION log_booking_create()
RETURNS TRIGGER 
AS $$
BEGIN
	INSERT INTO booking_status_log(booking_id, action)
    VALUES (NEW.booking_id, 'CREATE');
    RETURN NEW;
END;
$$ language plpgsql;

CREATE TRIGGER trigger_booking_create
AFTER INSERT
ON booking
FOR EACH ROW
EXECUTE FUNCTION log_booking_create();

CREATE OR REPLACE FUNCTION log_booking_edit()
RETURNS TRIGGER 
AS $$
BEGIN
    -- Cancel 
    IF OLD.status = 'Active' AND NEW.status = 'Cancelled' 
	THEN
       INSERT INTO booking_status_log(booking_id, action)
       VALUES (NEW.booking_id, 'CANCEL');
    END IF;

	-- Complete booking
    IF OLD.status = 'Active' AND NEW.status = 'Completed' 
	THEN
       INSERT INTO booking_status_log(booking_id, action)
       VALUES (NEW.booking_id, 'COMPLETE');
    END IF;
	
    RETURN NEW;
END;
$$ language plpgsql;

CREATE TRIGGER trigger_booking_edit
AFTER UPDATE OF status ON booking
FOR EACH ROW
EXECUTE FUNCTION log_booking_edit();



