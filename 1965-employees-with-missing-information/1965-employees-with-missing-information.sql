select employee_id
from Employees
left outer join Salaries
using (employee_id)
where salary is null

union

select employee_id
from Salaries
left outer join Employees
using (employee_id)
where name is null

order by employee_id;
