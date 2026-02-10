-- คนไข้ต้องการที่จะดูวันทำการในวัน จันทร์ พุธ ศุกร์ อาทิตย์ โดยมีช่วงเวลาตั้งแต่ 9 โมงเป็นต้นไป 
-- โดยคนไข้นั้นสามารถเห็นชื่อหมอได้ด้วย (โดนหากหมอมีเวรมากกว่า 1 วันที่กำหนดมาให้แสดงรวมกันในตารางเดียว)
-- และต้องการรู้ว่าหมอคนนั้นมีความถนัดด้านไหนและต้องบอกด้วยกว่ากี่ปี

SELECT
    d.dentist_id,
    d.first_name,
    d.last_name,
    (EXTRACT(YEAR FROM CURRENT_DATE) - d.career_start_year) AS experience_years,
    svc.expert_services,
    sh.work_days
FROM dentist d


JOIN (
    SELECT
        ei.dentist_id,
        STRING_AGG(DISTINCT s.service_name, ', ' ORDER BY s.service_name) AS expert_services
    FROM experts_in ei
    JOIN service s ON ei.service_id = s.service_id
    GROUP BY ei.dentist_id
) svc ON d.dentist_id = svc.dentist_id


JOIN (
    SELECT
        wf.dentist_id,
        STRING_AGG(DISTINCT wf.day_of_week::text, ', ' ORDER BY wf.day_of_week::text) AS work_days
    FROM works_in_shift wf
    WHERE wf.day_of_week IN ('Monday','Wednesday','Friday','Sunday')
      AND wf.start_time >= '9:00'
    GROUP BY wf.dentist_id
) sh ON d.dentist_id = sh.dentist_id

ORDER BY d.dentist_id;