SELECT
	*
FROM
	blog
WHERE
	body LIKE '%flag{%}%' 
	OR body LIKE '%FLAG{%}%'
    -- ILIKE '%flag{%}%' is ok too, but only flag and FLAG is stated in statment