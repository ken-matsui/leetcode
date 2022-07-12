select ifnull(round(avg(x), 2), 0) as average_sessions_per_user
from (
    select count(distinct session_id) as x
    from Activity 
    where activity_date between "2019-06-28" and "2019-07-27"
    group by user_id
) a;
