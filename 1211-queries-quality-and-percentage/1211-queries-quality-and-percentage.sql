select
    query_name,
    round(avg(rating / position), 2) as quality,
    round((count(case when rating < 3 then 1 end) / count(*)) * 100, 2) as poor_query_percentage
from Queries q1
group by query_name;
