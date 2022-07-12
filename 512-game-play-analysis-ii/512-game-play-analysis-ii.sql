with cte as (
    select player_id, min(event_date) as m
    from Activity
    group by player_id
)

select Activity.player_id, Activity.device_id
from Activity, cte c
where c.player_id = Activity.player_id
  and c.m = Activity.event_date;
