DO $$
DECLARE
    -- Variables to hold data during the test
    v_new_user_id INT;
    v_session_id INT;
    v_booking_id BIGINT;
    
    -- Target Details from Sample Data
    v_target_shop_id CONSTANT SMALLINT := 1; -- Smile Bright Dental
    v_target_dentist_id CONSTANT INT := 1;   -- Dr. Anan Suksan
    v_target_service_id CONSTANT INT := 1;   -- Teeth Cleaning
    v_target_date CONSTANT DATE := '2026-02-17'; -- A Monday (Dr. Anan works Mon)
    v_target_time CONSTANT TIME := '14:00:00';   -- 2:00 PM
BEGIN

    RAISE NOTICE '=== 1. TEST START: USER REGISTRATION ===';
    -- 1. Register a new user "Charlie"
    v_new_user_id := register_user(
        'Charlie', 
        'Day', 
        'charlie.day@email.com', 
        'securePassCharlie', 
        'Male', 
        '1990-12-25'
    );
    RAISE NOTICE 'User Created. ID: %', v_new_user_id;


    RAISE NOTICE '=== 2. TEST: LOGIN ===';
    -- 2. Login to get Session ID
    v_session_id := login_user(
        'charlie.day@email.com', 
        'securePassCharlie'
    );
    RAISE NOTICE 'User Logged In. Session ID: %', v_session_id;


    RAISE NOTICE '=== 3. TEST: BOOK APPOINTMENT ===';
    -- 3. Book Dr. Anan at Smile Bright for Cleaning
    v_booking_id := book_appointment(
        v_new_user_id,          -- Patient: Charlie
        v_target_dentist_id,    -- Dentist: Anan
        v_target_shop_id,       -- Shop: Smile Bright
        v_target_date,          -- Date: 2026-02-17
        v_target_time,          -- Time: 14:00
        ARRAY[v_target_service_id]::SMALLINT[] -- Service: Cleaning
    );
    RAISE NOTICE 'Booking Successful. Booking ID: %', v_booking_id;


    RAISE NOTICE '=== 4. TEST: COMPLETE BOOKING ===';
    -- 4. Mark the booking as "Completed"
    PERFORM complete_booking(v_booking_id);
    RAISE NOTICE 'Booking Marked as Completed.';


    RAISE NOTICE '=== 5. TEST: LOGOUT ===';
    -- 5. Logout the user
    PERFORM logout_user(v_session_id);
    RAISE NOTICE 'User Logged Out.';

END;
$$;



-- 1. Check User Status (Should see Charlie logged out)
SELECT us.status_id, us.user_id, u.email, us.login_time, us.logout_time, us.is_active
FROM user_status us
JOIN app_user u ON us.user_id = u.user_id
ORDER BY us.status_id DESC 
LIMIT 1;

-- 2. Check the Booking (Should be 'Completed' for Charlie)
SELECT b.booking_id, p.first_name as patient, d.first_name as dentist, 
       b.appointment_date, b.start_time, b.status
FROM booking b
JOIN patient p ON b.patient_id = p.patient_id
JOIN dentist d ON b.dentist_id = d.dentist_id
ORDER BY b.booking_id DESC 
LIMIT 1;

-- 3. Check Audit Logs (Register, Login, Logout)
SELECT * FROM auth_log ORDER BY log_id DESC LIMIT 3;

-- 4. Check Booking Logs (Create, Complete)
SELECT * FROM booking_status_log ORDER BY log_id DESC LIMIT 2;


