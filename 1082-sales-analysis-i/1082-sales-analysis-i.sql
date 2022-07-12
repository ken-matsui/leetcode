with cte as (
    select seller_id, sum(price) as s
    from Sales
    group by seller_id
)

select seller_id
from cte
where s = (
    select max(s)
    from cte
);
