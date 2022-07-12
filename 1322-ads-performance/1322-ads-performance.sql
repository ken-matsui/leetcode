with cte as (
    select
        ad_id,
        count(case when action = 'Clicked' then 1 end) as clicks,
        count(case when action = 'Viewed' then 1 end) as views
    from Ads
    group by ad_id
)

select ad_id, if(clicks + views = 0, 0.00, round((clicks / (clicks + views)) * 100, 2)) as ctr
from cte
order by ctr desc, ad_id asc;
