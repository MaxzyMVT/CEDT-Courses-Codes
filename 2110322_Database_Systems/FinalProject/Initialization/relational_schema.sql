-- CREATE DATABASE Dentist_Booking_System;


CREATE TYPE booking_status AS ENUM('Active','Cancelled','Completed');
CREATE TYPE day_of_week AS ENUM('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday');


-- Entities

CREATE TABLE dentist_shop (
    shop_id SMALLINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    shop_name VARCHAR(255) NOT NULL,
    number_of_operatory INT NOT NULL CHECK (number_of_operatory >= 0),
    map_url VARCHAR(255) NOT NULL, -- Renamed for clarity
    province VARCHAR(50) NOT NULL,
    district VARCHAR(50) NOT NULL,
    subdistrict VARCHAR(50) NOT NULL,
    building_number VARCHAR(20) NOT NULL,
    street VARCHAR(255) NOT NULL,
    zipcode CHAR(5) NOT NULL CHECK (zipcode ~ '^[0-9]{5}$'),    -- Zipcode is exactly 5 digits
    CONSTRAINT unique_address UNIQUE (province, district, subdistrict, building_number, street, zipcode),   -- No shop located in the same location
    description TEXT
);

CREATE TABLE facility (
    shop_id SMALLINT,
    facility_name VARCHAR(255),
    quantity INT NOT NULL CHECK (quantity >= 0),
    description TEXT,
    CONSTRAINT fk_shop_facility FOREIGN KEY (shop_id) REFERENCES dentist_shop(shop_id),
    CONSTRAINT pk_facility PRIMARY KEY (shop_id, facility_name)
);

CREATE TABLE shop_phone_number (
    shop_id SMALLINT,
    phone_number VARCHAR(20) NOT NULL,
    CONSTRAINT fk_shop_phone FOREIGN KEY (shop_id) REFERENCES dentist_shop(shop_id),
    CONSTRAINT pk_shop_phone PRIMARY KEY (shop_id, phone_number)
);

CREATE TABLE dentist (
    dentist_id INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    first_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL,
    career_start_year INT NOT NULL
);

CREATE TABLE service (
    service_id SMALLINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    service_name VARCHAR(255) UNIQUE NOT NULL,
    min_duration_minutes INT NOT NULL CHECK (min_duration_minutes >= 0),
    max_duration_minutes INT NOT NULL CHECK (max_duration_minutes >= min_duration_minutes),
    min_price NUMERIC(10, 2) NOT NULL CHECK (min_price >= 0),
    max_price NUMERIC(10, 2) NOT NULL CHECK (max_price >= min_price),
    description TEXT
);

CREATE TABLE app_user (
    user_id INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    email VARCHAR(255) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL,  -- Should be hashed for privacy / Renamed for clarity
    admin_flag BOOLEAN NOT NULL DEFAULT FALSE
);

CREATE TABLE patient (
    patient_id INT PRIMARY KEY,
    first_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL,
    gender VARCHAR(20),
    date_of_birth DATE NOT NULL,
    CONSTRAINT fk_user_patient FOREIGN KEY (patient_id) REFERENCES app_user(user_id)
);


-- Basic Relationships

CREATE TABLE works_in (
    dentist_id INT,
    shop_id SMALLINT,
    CONSTRAINT fk_dentist_work FOREIGN KEY (dentist_id) REFERENCES dentist(dentist_id),
    CONSTRAINT fk_shop_work FOREIGN KEY (shop_id) REFERENCES dentist_shop(shop_id),
    CONSTRAINT pk_works_in PRIMARY KEY (dentist_id, shop_id)
);

CREATE TABLE works_in_shift ( -- Shifts of Dentist d who works in Shop s
    dentist_id INT,
    shop_id SMALLINT,
    day_of_week day_of_week NOT NULL,
    start_time TIME NOT NULL,
    end_time TIME NOT NULL,
    CONSTRAINT fk_dentist_work_shift FOREIGN KEY (dentist_id, shop_id) REFERENCES works_in(dentist_id, shop_id),
    CONSTRAINT pk_works_in_shift PRIMARY KEY (dentist_id, day_of_week, start_time) -- The same dentist won't work at the same time on the same day
);

CREATE TABLE experts_in (
    dentist_id INT,
    service_id SMALLINT,
    CONSTRAINT fk_dentist_expert FOREIGN KEY (dentist_id) REFERENCES dentist(dentist_id),
    CONSTRAINT fk_service_expert FOREIGN KEY (service_id) REFERENCES service(service_id),
    CONSTRAINT pk_experts_in PRIMARY KEY (dentist_id, service_id)
);

CREATE TABLE provides (
    shop_id SMALLINT,
    service_id SMALLINT,
    CONSTRAINT fk_shop_provide FOREIGN KEY (shop_id) REFERENCES dentist_shop(shop_id),
    CONSTRAINT fk_service_provide FOREIGN KEY (service_id) REFERENCES service(service_id),
    CONSTRAINT pk_provides PRIMARY KEY (shop_id, service_id)
);


-- Booking Entity & Relationship

CREATE TABLE booking (
    booking_id BIGINT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    patient_id INT NOT NULL,
    dentist_id INT NOT NULL,
    shop_id SMALLINT NOT NULL,
    status booking_status NOT NULL,
    booking_time TIMESTAMP NOT NULL DEFAULT NOW(),
    appointment_date DATE NOT NULL,
    start_time TIME NOT NULL,
    end_time TIME NOT NULL,
    CONSTRAINT fk_patient_booking FOREIGN KEY (patient_id) REFERENCES patient(patient_id),
    CONSTRAINT fk_booking_location FOREIGN KEY (dentist_id, shop_id) REFERENCES works_in(dentist_id, shop_id)
);

CREATE TABLE books_service (
    booking_id BIGINT,
    service_id SMALLINT,
    CONSTRAINT fk_booking_service FOREIGN KEY (booking_id) REFERENCES booking(booking_id),
    CONSTRAINT fk_service_booking FOREIGN KEY (service_id) REFERENCES service(service_id),
    CONSTRAINT pk_books_service PRIMARY KEY (booking_id, service_id)
);

-- Indexes

-- One patient could only book 1 booking at a time
CREATE UNIQUE INDEX idx_one_active_booking_per_patient
ON booking (patient_id)
WHERE status = 'Active';