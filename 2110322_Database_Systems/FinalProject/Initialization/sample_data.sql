INSERT INTO dentist_shop
(shop_name, number_of_operatory, map_url, province, district, subdistrict,
 building_number, street, zipcode, description)
VALUES
('Smile Bright Dental', 5, 'https://maps.google.com/?q=smilebright',
 'Bangkok', 'Pathum Wan', 'Wang Mai',
 '123', 'Rama I Road', '10330', 'Modern dental clinic near BTS'),
('Happy Tooth Clinic', 3, 'https://maps.google.com/?q=happytooth',
 'Bangkok', 'Chatuchak', 'Lat Yao',
 '55/7', 'Phahonyothin Road', '10900', 'Affordable family dental clinic');


INSERT INTO dentist_shop
(shop_name, number_of_operatory, map_url, province, district, subdistrict,
 building_number, street, zipcode, description)
VALUES
('White Pearl Dental', 4, 'https://maps.google.com/?q=whitepearl',
 'Chiang Mai', 'Mueang', 'Suthep',
 '89', 'Huay Kaew Road', '50200', 'Premium dental clinic'),
('ToothCare Plus', 6, 'https://maps.google.com/?q=toothcareplus',
 'Bangkok', 'Bang Kapi', 'Hua Mak',
 '12/3', 'Ramkhamhaeng Road', '10240', 'Large clinic with many specialists');


INSERT INTO facility
(shop_id, facility_name, quantity, description)
VALUES
(1, 'Dental Chair', 5, 'Standard dental chairs'),
(1, 'X-Ray Machine', 1, 'Digital X-ray'),
(2, 'Dental Chair', 3, 'Basic dental chairs');

INSERT INTO facility
(shop_id, facility_name, quantity, description)
VALUES
(3, 'Dental Chair', 4, 'Premium chairs'),
(3, 'CT Scanner', 1, '3D dental CT'),
(4, 'Dental Chair', 6, 'Standard chairs'),
(4, 'Sterilizer', 2, 'Equipment sterilization machines');

INSERT INTO shop_phone_number
(shop_id, phone_number)
VALUES
(1, '02-123-4567'),
(1, '081-111-2222'),
(2, '02-987-6543');

INSERT INTO dentist
(first_name, last_name, career_start_year)
VALUES
('Anan', 'Suksan', 2010),
('Pim', 'Wongchai', 2015);

INSERT INTO service
(service_name, min_duration_minutes, max_duration_minutes,
 min_price, max_price, description)
VALUES
('Teeth Cleaning', 30, 45, 800.00, 1500.00, 'Basic dental cleaning'),
('Tooth Filling', 30, 60, 1000.00, 3000.00, 'Composite filling'),
('Root Canal', 60, 120, 5000.00, 12000.00, 'Root canal treatment');

INSERT INTO app_user
(email, password_hash, admin_flag)
VALUES
('john.doe@email.com', 'hashed_password_123', FALSE),
('admin@dentist.com', 'hashed_admin_pw', TRUE);

INSERT INTO patient
(patient_id, first_name, last_name, gender, date_of_birth)
VALUES
(1, 'John', 'Doe', 'Male', '1998-04-15');

INSERT INTO works_in
(dentist_id, shop_id)
VALUES
(1, 1),
(2, 1),
(2, 2);

INSERT INTO works_in_shift
(dentist_id, shop_id, day_of_week, start_time, end_time)
VALUES
(1, 1, 'Monday', '09:00', '17:00'),
(1, 1, 'Wednesday', '09:00', '17:00'),
(2, 1, 'Friday', '10:00', '18:00'),
(2, 2, 'Saturday', '09:00', '15:00');

INSERT INTO experts_in
(dentist_id, service_id)
VALUES
(1, 1),
(1, 2),
(2, 2),
(2, 3);

INSERT INTO provides
(shop_id, service_id)
VALUES
(1, 1),
(1, 2),
(1, 3),
(2, 1),
(2, 2);

INSERT INTO booking
(patient_id, dentist_id, shop_id, status,
 appointment_date, start_time, end_time)
VALUES
(1, 1, 1, 'Active', '2026-02-10', '10:00', '10:45');

INSERT INTO books_service
(booking_id, service_id)
VALUES
(1, 1);

INSERT INTO shop_phone_number
(shop_id, phone_number)
VALUES
(3, '053-222-333'),
(4, '02-555-9999'),
(4, '089-777-8888');

INSERT INTO dentist
(first_name, last_name, career_start_year)
VALUES
('Krit', 'Limsakul', 2008),
('Nicha', 'Srisawat', 2018),
('Somchai', 'Pradit', 2000);

INSERT INTO service
(service_name, min_duration_minutes, max_duration_minutes,
 min_price, max_price, description)
VALUES
('Teeth Whitening', 45, 90, 3000.00, 8000.00, 'Professional whitening'),
('Dental Implant', 90, 180, 30000.00, 80000.00, 'Implant surgery');

INSERT INTO app_user
(email, password_hash, admin_flag)
VALUES
('alice@email.com', 'hashed_pw_alice', FALSE),
('bob@email.com', 'hashed_pw_bob', FALSE),
('staff@toothcareplus.com', 'hashed_staff_pw', TRUE);

INSERT INTO patient
(patient_id, first_name, last_name, gender, date_of_birth)
VALUES
(3, 'Alice', 'Brown', 'Female', '2001-09-21'),
(4, 'Bob', 'Smith', 'Male', '1995-01-10');

INSERT INTO works_in
(dentist_id, shop_id)
VALUES
(3, 1),
(3, 3),
(4, 4),
(5, 2),
(5, 4);

INSERT INTO works_in_shift
(dentist_id, shop_id, day_of_week, start_time, end_time)
VALUES
(3, 1, 'Tuesday', '09:00', '16:00'),
(3, 3, 'Thursday', '10:00', '18:00'),
(4, 4, 'Monday', '09:00', '17:00'),
(5, 2, 'Wednesday', '10:00', '17:00'),
(5, 4, 'Friday', '09:00', '16:00');

INSERT INTO experts_in
(dentist_id, service_id)
VALUES
(3, 1),
(3, 4),
(4, 2),
(4, 5),
(5, 3),
(5, 5);

INSERT INTO provides
(shop_id, service_id)
VALUES
(2, 3),
(2, 4),
(3, 1),
(3, 4),
(3, 5),
(4, 1),
(4, 2),
(4, 5);

INSERT INTO booking
(patient_id, dentist_id, shop_id, status,
 appointment_date, start_time, end_time)
VALUES
(3, 3, 1, 'Completed', '2026-01-15', '09:00', '09:45'),
(4, 5, 2, 'Cancelled', '2026-02-01', '11:00', '12:00'),
(1, 2, 1, 'Completed', '2025-12-20', '13:00', '14:00');

INSERT INTO books_service
(booking_id, service_id)
VALUES
(2, 1),
(3, 3),
(4, 2);
