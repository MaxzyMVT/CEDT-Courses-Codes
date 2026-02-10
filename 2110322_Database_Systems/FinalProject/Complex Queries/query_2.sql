-- Patient wants to see all dentists in a shop with years of experience and all expertise

SELECT
    d.first_name, d.last_name,
    EXTRACT(YEAR FROM CURRENT_DATE) - d.career_start_year AS years_of_experience,
    STRING_AGG(s.service_name, ', ' ORDER BY s.service_name) AS expertise_list
FROM dentist d
    JOIN works_in wi 
ON d.dentist_id = wi.dentist_id
    JOIN dentist_shop ds 
ON wi.shop_id = ds.shop_id
    JOIN experts_in ei 
ON d.dentist_id = ei.dentist_id
    JOIN service s 
ON ei.service_id = s.service_id
WHERE ds.shop_name = 'Smile Bright Dental'
GROUP BY d.dentist_id;
