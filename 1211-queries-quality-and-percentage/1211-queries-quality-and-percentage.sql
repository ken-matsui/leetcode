select
    query_name,
    round(avg(rating / position), 2) as quality,
    round(
        (
            (
                select count(*)
                from Queries q2
                where q1.query_name = q2.query_name
                  and rating < 3
            )  
            /
            count(*)
        ) * 100
    , 2) as poor_query_percentage
from Queries q1
group by query_name;
