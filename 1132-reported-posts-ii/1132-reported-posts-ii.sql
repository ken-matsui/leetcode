with cte as (
    select distinct post_id, action_date
    from Actions
    where extra = 'spam'
)

select round(avg(percent) * 100, 2) as average_daily_percent
from (
    select
        (
            count(action_date) - count(case when remove_date is null then 1 end)
        ) / count(action_date) as percent
    from cte
    left join Removals
    using (post_id)
    group by action_date
) c;
