-- สรุป ชั่วโมงทำงานรวม Per Weak ของหมอแต่ละคนในแต่ละร้าน(รวมทุก shift) // admin view

SELECT
    ds.shop_name, d.first_name, d.last_name,
    ROUND(SUM(EXTRACT(HOUR FROM (ws.end_time - ws.start_time))), 2) AS weekly_hours
FROM works_in_shift ws
JOIN dentist d 
    ON ws.dentist_id = d.dentist_id
JOIN dentist_shop ds 
    ON ws.shop_id = ds.shop_id
GROUP BY ds.shop_id, d.dentist_id
ORDER BY 
    ds.shop_name ASC, 
    weekly_hours DESC;