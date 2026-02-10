WITH sum_expense as (
	SELECT ddate, pname, SUM(amt) AS sum
	FROM expense
	GROUP BY ddate, pname
)

SELECT 
	se.ddate,
	se.pname 
FROM (
		SELECT
			se.ddate, MAX(sum) as max
		FROM sum_expense as se
		GROUP BY se.ddate
	) as mx
JOIN
	sum_expense as se
	ON mx.ddate = se.ddate
	AND mx.max = se.sum
GROUP BY 
	se.ddate,
	se.pname
ORDER BY
	se.ddate,
	se.pname