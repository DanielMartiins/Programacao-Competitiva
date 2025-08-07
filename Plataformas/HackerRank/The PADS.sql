SELECT
    CONCAT(O.NAME, '(', SUBSTRING(O.Occupation, 1, 1), ')')
FROM
    OCCUPATIONS O
ORDER BY
    O.NAME;

SELECT
    'There are a total of',
    count(*) AS total,
    CONCAT(LOWER(O.Occupation), 's.')
FROM
    OCCUPATIONS O
GROUP BY
    O.Occupation
ORDER BY
    total, O.Occupation;