SELECT
    N,
    CASE 
        WHEN P IS NULL THEN 'Root'
        WHEN P IS NOT NULL AND EXISTS (
            SELECT 1 FROM BST AS B2 WHERE B2.P = B1.N
        ) THEN 'Inner'
        ELSE 'Leaf'    
    END
FROM BST AS B1
ORDER BY N;