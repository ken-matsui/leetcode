with cte as (
    select seller_id, order_cost
    from Orders
    where year(sale_date) = 2020
)

select seller_name
from Seller
left join cte
using (seller_id)
where order_cost is null
order by seller_name;
