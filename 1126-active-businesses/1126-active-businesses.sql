with cte as (
    select event_type, avg(occurences) as avg_occ
    from Events
    group by event_type
)

select business_id
from Events
left join cte
using (event_type)
where occurences > avg_occ
group by business_id
having count(business_id) > 1;
