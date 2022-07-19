with cte as (
    select player_id, min(event_date) as event_date
    from Activity
    group by player_id
)

select
    round(
        count(distinct a.player_id)
        /
        (select count(distinct player_id) from Activity),
        2
    ) as fraction
from cte, Activity a
where date_add(cte.event_date, interval 1 day) = a.event_date
  and cte.player_id = a.player_id;
