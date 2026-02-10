WITH sum_expense as (
	SELECT
		d.ddate,
		n.pname,
		COALESCE(SUM(amt), 0) as sum
	FROM
		(SELECT DISTINCT pname FROM expense) as n
	CROSS JOIN
		(SELECT DISTINCT ddate FROM expense) as d
	LEFT JOIN
		expense e
		ON e.ddate = d.ddate AND e.pname = n.pname
	GROUP BY d.ddate, n.pname
)

SELECT 
	se.ddate,
	se.pname 
FROM (
		SELECT
			se.ddate, MIN(sum) as min
		FROM sum_expense as se
		GROUP BY se.ddate
	) as mn
JOIN
	sum_expense as se
	ON mn.ddate = se.ddate
	AND mn.min = se.sum
GROUP BY 
	se.ddate,
	se.pname
ORDER BY
	se.ddate,
	se.pname