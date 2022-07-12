select
    c.country_name,
    (case
        when avg(w.weather_state) <= 15 then 'Cold'
        when avg(w.weather_state) >= 25 then 'Hot'
        else 'Warm'
    end) as weather_type
from Weather w
left join Countries c
on w.country_id = c.country_id
where year(day) = 2019
  and month(day) = 11
group by w.country_id;
