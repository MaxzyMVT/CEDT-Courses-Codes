WITH movie_counts as (
    SELECT 
        m.mid as id, 
        m.title, 
        COUNT(c.cid) as total_views
    FROM movie m
    JOIN customer c ON m.mid = c.mid
    GROUP BY m.mid, m.title
)

SELECT 
	id, 
	title, 
	total_views
FROM 
	movie_counts
WHERE 
	total_views = (SELECT MAX(total_views) FROM movie_counts)
ORDER BY 
	title ASC;