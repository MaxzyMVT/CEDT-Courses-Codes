WITH diverse_product as (
	SELECT pcategory, AVG(pprice) as avg
	FROM product
	GROUP BY pcategory
	ORDER BY COUNT(*) DESC
	FETCH FIRST 1 ROWS WITH TIES
)

SELECT DISTINCT
	c.cname
FROM
	customer c
JOIN
	placement m
	ON m.cid = c.cid
JOIN
	product p
	ON m.pid = p.pid
WHERE 
	p.pprice > (SELECT avg FROM diverse_product)
ORDER BY
	c.cname