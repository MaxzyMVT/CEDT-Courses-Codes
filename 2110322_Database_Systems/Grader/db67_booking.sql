SELECT
	room_type,
	COUNT(1) as booking_count
FROM
	bookings
WHERE
	check_in_date >= '2024-01-01'
	AND check_in_date < '2025-01-01'
GROUP BY
	room_type
ORDER BY
	booking_count DESC,
	room_type ASC
LIMIT 1