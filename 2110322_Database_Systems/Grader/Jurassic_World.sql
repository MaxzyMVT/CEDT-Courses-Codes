WITH dinosaur_sum AS (
SELECT
	dino_name,
	dino_type,
	SUM(amount) AS total_amount
FROM 
	dinosaurs
GROUP BY
	dino_name,
	dino_type
)

SELECT 
	dino_name,
	dino_type,
	total_amount
FROM
	dinosaur_sum
ORDER BY
	total_amount DESC,
	dino_name ASC,
	dino_type ASC
LIMIT 1
