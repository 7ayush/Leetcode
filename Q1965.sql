elect e.employee_id as "employee_id" from employees as e left join salaries as s
on e.employee_id = s.employee_id where s.salary is null
union
select s.employee_id as "employee_id" from salaries as s left join employees as e
on s.employee_id = e.employee_id where e.name is null
order by employee_id;

select employee_id from Employees where employee_id not in (select employee_id from salaries)
UNION
select employee_id from salaries where employee_id not in (select employee_id from Employees)
order by employee_id;
