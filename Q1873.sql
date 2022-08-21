SELECT employee_id, 
CASE
    WHEN employee_id%2=1 AND name not like "M%"
        THEN salary
        ELSE 0
    END
    AS `bonus`
FROM employees ORDER BY employee_id;

SELECT employee_id, if(employee_id%2=1 and name not like "M%",salary,0) as bonus from employees order by employee_id;
