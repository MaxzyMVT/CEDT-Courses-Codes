SELECT 
	tid, pname, ddate, SUM(amt)
FROM expense
GROUP BY ddate