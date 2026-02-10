-------------------------------- TEST --------------------------------

-- John (user_id = 1) ดู booking ของตัวเอง (booking_id = 1)
SELECT *
FROM view_booking(1, 1);

-- John (user_id = 1) พยายามดู booking ของ Alice (booking_id = 2)
SELECT *
FROM view_booking(2, 1);

-- Admin (user_id = 2) ดู booking ใดก็ได้
SELECT *
FROM view_booking(1, 2);

-- แก้เวลา booking_id = 1 (Active)
SELECT edit_booking_time(
    1,              -- booking_id
    1,              -- user_id
    '2026-02-10',   -- new date
    '11:00',        -- new start
    '11:45'         -- new end
);

-- booking_id = 2 เป็น Completed
SELECT edit_booking_time(
    2,
    3,
    '2026-01-15',
    '10:00',
    '10:45'
);
-- เขียนช่วงเวลาผิด
SELECT edit_booking_time(
    1,
    1,
    '2026-02-10',
    '14:00',
    '13:00'
);




-- booking เวลาไปทับ booking อื่น (insert ข้อมูลด้านล่างก่อน)
SELECT * FROM patient NATURAL JOIN booking ORDER BY booking_id DESC;

INSERT INTO booking (
    patient_id,
    dentist_id,
    shop_id,
    status,
    appointment_date,
    start_time,
    end_time
)
VALUES (
    3,              
    1,              
    1,              
    'Active',
    '2026-02-10',   
    '12:00',        
    '12:45'
);

-- เวลาทับ
SELECT edit_booking_time(
    1,
    1,
    '2026-02-10',
    '12:00',
    '12:45'
);




-- ลบ booking ตัวเอง (Make Cancelled)
SELECT delete_booking(1, 1);
-- ลบ booking คนอื่น
SELECT delete_booking(2, 1);
-- Admin ลบ
SELECT delete_booking(3, 2);
-- ดู log
SELECT *
FROM booking_changelog
ORDER BY performed_at DESC;

SELECT * 
FROM booking_status_log 
ORDER BY log_id DESC;
