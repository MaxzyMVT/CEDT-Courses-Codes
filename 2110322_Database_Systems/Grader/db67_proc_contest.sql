WITH passed_cnt as (
SELECT
	tid,
	COUNT(DISTINCT cid) as cnt
FROM
	submit s
WHERE
	score = 100
GROUP BY
	tid
)


SELECT
	aname,
	tname
FROM
	passed_cnt p
JOIN
	task t
	ON t.tid = p.tid
JOIN
	author a
	ON a.aid = t.aid
WHERE
	p.cnt = (SELECT MAX(p.cnt) FROM passed_cnt p)
ORDER BY
	p.cnt DESC,
	a.aid ASC
	
-- !! ODD TESTCASE !! --