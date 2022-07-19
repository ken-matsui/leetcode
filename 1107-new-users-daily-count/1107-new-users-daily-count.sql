select
    activity_date as login_date,
    count(distinct user_id) as user_count
from Traffic
where activity_date >= date_sub('2019-06-30', interval 90 day)
  and (user_id, activity_date) in (
      select user_id, min(activity_date)
      from Traffic
      where activity = 'login'
      group by user_id
  )
group by activity_date;
