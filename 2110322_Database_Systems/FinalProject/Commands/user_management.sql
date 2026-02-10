-- =========================
-- TABLE: user_status (Session/Status table)
-- =========================

CREATE TABLE user_status(                                  -- ตารางชื่อ user_status เพื่อเก็บ "สถานะการเข้าใช้งาน" (session)
    status_id BIGSERIAL PRIMARY KEY,                       -- status_id = Session ID (DB auto-generated)
    user_id INT NOT NULL,                                  -- user_id = Owner of this session (References app_user.user_id)
    login_time TIMESTAMP DEFAULT NOW(),                    -- login_time = Time of login (Defaults to NOW)
    logout_time TIMESTAMP,                                 -- logout_time = Time of logout (NULL initially)
    is_active BOOLEAN DEFAULT TRUE NOT NULL
);


-- =========================
-- TABLE: auth_log (Audit/Log table)
-- =========================

CREATE TABLE auth_log(                                     -- สร้างตารางชื่อ auth_log เพื่อเก็บประวัติ event
    log_id SERIAL PRIMARY KEY,                             -- log_id = Log ID
    user_id INT,                                           -- user_id = User who triggered the event
    action VARCHAR(20),                                    -- action = 'REGISTER', 'LOGIN', 'LOGOUT'
    log_time TIMESTAMP DEFAULT NOW()                       -- log_time = Time of event
);


-- =========================
-- FUNCTION: register_user (REGISTER)
-- =========================

CREATE OR REPLACE FUNCTION register_user(                  -- สร้าง/แก้ฟังก์ชัน register_user สำหรับ "สมัครสมาชิก"
    u_first_name VARCHAR,                                  -- parameter: First Name
    u_last_name  VARCHAR,                                  -- parameter: Last Name
    u_email      VARCHAR,                                  -- parameter: Email (Login ID)
    u_password   VARCHAR,                                  -- parameter: Password
    u_gender     VARCHAR,                                  -- parameter: Gender
    u_dob        DATE                                      -- parameter: Date of Birth
)
RETURNS INT                                                -- Returns the new user_id
LANGUAGE plpgsql AS $$
DECLARE
    new_user_id INT;                                       -- Variable to hold the new user_id
BEGIN

    -- 1. Check if email already exists
    IF EXISTS (SELECT 1 FROM app_user WHERE email = u_email) THEN
        RAISE EXCEPTION 'Email already exists';
    END IF;

    -- 2. Create user account in app_user table
    INSERT INTO app_user(email, password_hash, admin_flag)
    VALUES (u_email, u_password, FALSE)                    -- Default admin_flag = FALSE (Patient)
    RETURNING user_id INTO new_user_id;                    -- Capture the generated user_id

    -- 3. Create patient profile in patient table
    INSERT INTO patient(patient_id, first_name, last_name, gender, date_of_birth)
    VALUES (new_user_id, u_first_name, u_last_name, u_gender, u_dob);

    RETURN new_user_id;                                    -- Return the ID to indicate success

END;
$$;


-- =========================
-- FUNCTION: login_user (LOGIN)
-- =========================

CREATE OR REPLACE FUNCTION login_user(                    -- สร้าง/แก้ฟังก์ชัน login_user สำหรับ "เข้าสู่ระบบ"
    u_email VARCHAR,                                      -- parameter: Email
    u_password VARCHAR                                    -- parameter: Password
)
RETURNS INT                                               -- Returns status_id (Session ID)
LANGUAGE plpgsql AS $$
DECLARE
    v_user_id INT;
    v_status_id INT;
BEGIN

    -- 1. Validate Credentials
    SELECT user_id INTO v_user_id
    FROM app_user
    WHERE email = u_email AND password_hash = u_password;

    -- 2. If user not found, raise error
    IF v_user_id IS NULL THEN
        RAISE EXCEPTION 'Invalid email or password';
    END IF;

    -- 3. Create Session (Set is_active = TRUE)
    INSERT INTO user_status(user_id, login_time, logout_time, is_active)
    VALUES (v_user_id, NOW(), NULL, TRUE)                 -- **SET is_active = TRUE** for book_appointment check
    RETURNING status_id INTO v_status_id;

    RETURN v_status_id;

END;
$$;


-- =========================
-- FUNCTION: logout_user (LOGOUT)
-- =========================

CREATE OR REPLACE FUNCTION logout_user(                   -- สร้าง/แก้ฟังก์ชัน logout_user สำหรับ "ออกจากระบบ"
    p_status_id INT                                       -- parameter: status_id (session id)
)
RETURNS VOID
LANGUAGE plpgsql AS $$
BEGIN

    -- 1. Close Session (Update logout_time AND set is_active = FALSE)
    UPDATE user_status
    SET logout_time = NOW(),
        is_active = FALSE                                 -- **SET is_active = FALSE**
    WHERE status_id = p_status_id
      AND is_active = TRUE;                               -- Update only if currently active

    -- 2. Check if update occurred
    IF NOT FOUND THEN
        RAISE EXCEPTION 'Status not found or already logged out';
    END IF;

END;
$$;


-- =========================
-- TRIGGER FUNCTION & TRIGGERS
-- =========================

CREATE OR REPLACE FUNCTION log_auth_action()
RETURNS TRIGGER
LANGUAGE plpgsql AS $$
BEGIN
    INSERT INTO auth_log(user_id, action)
    VALUES (NEW.user_id, TG_ARGV[0]);
    RETURN NEW;
END;
$$;

-- Trigger: Register
CREATE TRIGGER trg_register_log
AFTER INSERT ON app_user
FOR EACH ROW
EXECUTE FUNCTION log_auth_action('REGISTER');

-- Trigger: Login
CREATE TRIGGER trg_login_log
AFTER INSERT ON user_status
FOR EACH ROW
EXECUTE FUNCTION log_auth_action('LOGIN');

-- Trigger: Logout
CREATE TRIGGER trg_logout_log
AFTER UPDATE ON user_status
FOR EACH ROW
WHEN (OLD.is_active = TRUE AND NEW.is_active = FALSE)     -- Trigger when status changes to inactive
EXECUTE FUNCTION log_auth_action('LOGOUT');