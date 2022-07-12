with cte as (
    select project_id, count(*) as cnt
    from Project
    group by project_id
)

select project_id
from cte
where cnt = (
    select max(cnt)
    from cte
);
