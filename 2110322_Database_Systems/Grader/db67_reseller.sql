SELECT 
	pname,
	pprice,
	SUM(quantity_sold) as total_sales
FROM
	product as p
JOIN 
	product_sales as ps
	ON p.pid = ps.pid
WHERE
	sale_date BETWEEN '2022-01-01' AND '2025-01-01'
GROUP BY
	p.pid
HAVING
	SUM(quantity_sold) <= 100
ORDER BY
	total_sales DESC,
	pprice ASC,
	pname ASC
LIMIT 3