select distinct(followee) as follower, count(followee) as num
from Follow
where followee in (
    select distinct follower
    from Follow
)
group by followee
order by followee;
