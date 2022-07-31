SELECT employee_id, IF((employee_id MOD 2 =1) AND (emp.name not like "M%"),emp.salary,0) as `bonus`
from employees as emp order by employee_id;


SELECT employee_id, 
CASE 
    WHEN employee_id%2=1 AND name not like "M%" 
        THEN salary 
        ELSE 0 
    END 
    AS `bonus`
FROM employees ORDER BY employee_id;
