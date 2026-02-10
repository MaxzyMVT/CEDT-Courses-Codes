SELECT
	c.name,
	SUM(amount * price) as total
FROM
	customers as c
JOIN
	orders as o
	ON c.id = c_id
JOIN
	desserts as d
	ON d.id = d_id
GROUP BY
	c.name
ORDER BY
	SUM(amount * price) DESC,
	c.id ASC