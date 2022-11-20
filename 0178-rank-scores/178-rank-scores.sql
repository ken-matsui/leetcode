select score, dense_rank() over(order by score desc) as "Rank"
from (
    select score
    from scores 
    order by score desc 
) s;
