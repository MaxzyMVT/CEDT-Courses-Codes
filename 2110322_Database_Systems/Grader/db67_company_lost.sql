SELECT
	order_year as order_year,
	ROUND(SUM(p.unit_price * od.quantity * od.discount)::numeric, 2) as discount_amount
FROM (
	SELECT 
		oid,
		EXTRACT(YEAR from order_date) as order_year
	FROM orders
) AS o
JOIN
	order_details as od
	ON o.oid = od.oid
JOIN
	products as p
	ON od.pid = p.pid
GROUP BY
	order_year
ORDER BY
	order_year DESC
