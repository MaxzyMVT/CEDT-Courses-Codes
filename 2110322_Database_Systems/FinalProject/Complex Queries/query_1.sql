-- Patient wants to find dentists who เลือกมาจาก Service , shop_name , day_of_week ที่เราต้องการ

SELECT DISTINCT
    d.first_name, d.last_name,
    EXTRACT(YEAR FROM CURRENT_DATE) - d.career_start_year AS years_of_experience
FROM dentist d
JOIN experts_in ei
    ON d.dentist_id = ei.dentist_id
JOIN service s
    ON ei.service_id = s.service_id
JOIN works_in wi
    ON d.dentist_id = wi.dentist_id
JOIN dentist_shop ds
    ON wi.shop_id = ds.shop_id
JOIN works_in_shift ws
    ON ws.dentist_id = wi.dentist_id AND ws.shop_id = wi.shop_id
WHERE s.service_name = 'Tooth Filling'
    AND ds.shop_name = 'Happy Tooth Clinic'
    AND ws.day_of_week = 'Saturday';
