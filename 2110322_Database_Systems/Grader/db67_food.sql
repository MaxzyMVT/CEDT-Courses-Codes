SELECT
	name,
	unit_price
FROM
	product
WHERE
	unit_price > 2000
	AND category_name in ('food', 'drink')
ORDER BY
	unit_price DESC