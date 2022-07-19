with cte as (
    select
        project_id,
        employee_id,
        rank() over(
            partition by project_id
            order by experience_years desc
        ) as rnk
    from Project
    left join Employee
    using (employee_id)
)

select project_id, employee_id
from cte
where rnk = 1;
