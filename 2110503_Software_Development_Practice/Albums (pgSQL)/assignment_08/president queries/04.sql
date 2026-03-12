SELECT presi_lastname, firstlady_firstname
FROM president p
JOIN firstlady f
ON p.firstlady_num = f.firstlady_num
WHERE presi_lastname LIKE 'D%';