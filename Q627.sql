UPDATE Salary SET sex=(
    CASE sex
        WHEN 'm' THEN 'f'
        WHEN 'f' THEN 'm'
    END
) 
UPDATE Salary SET sex=(
    CASE sex
        WHEN 'm' THEN 'f' ELSE 'm'
    END
) 

UPDATE Salary set sex= IF(sex='m','f','m');
