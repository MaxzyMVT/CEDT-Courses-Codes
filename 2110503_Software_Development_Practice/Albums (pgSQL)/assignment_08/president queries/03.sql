SELECT firstlady_birthplace, COUNT(*)
FROM firstlady
WHERE firstlady_birthplace LIKE 'N%'
GROUP BY firstlady_birthplace;