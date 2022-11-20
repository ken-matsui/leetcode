with cte as (
    select departmentId, max(salary) as salary
    from Employee
    group by departmentId
)

select
    d.name as Department,
    e.name as Employee,
    e.salary as Salary
from cte
left join Employee e
using (departmentId, salary)
left join Department d
on e.departmentId = d.id;
