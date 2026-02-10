SELECT
	first_name
FROM
	customer as c
JOIN 
	invoice as i
	ON c.cus_id = i.cus_id
GROUP BY
	c.cus_id, 
	first_name
ORDER BY
	SUM(total_spent) DESC,
	COUNT(*) ASC,
	c.cus_id ASC
LIMIT 1