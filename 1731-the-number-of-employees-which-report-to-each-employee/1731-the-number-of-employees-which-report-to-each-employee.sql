with cte as (
    select
        reports_to,
        count(reports_to) as reports_count,
        round(avg(age)) as average_age
    from Employees
    where reports_to is not null
    group by reports_to
)

select
    employee_id,
    name,
    reports_count,
    average_age
from Employees, cte
where employee_id = cte.reports_to
order by employee_id;
