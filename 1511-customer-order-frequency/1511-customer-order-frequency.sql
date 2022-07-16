with cte as (
    select
        customer_id,
        sum(case when order_date between '2020-06-01' and '2020-06-30' then quantity * price else 0 end) as june,
        sum(case when order_date between '2020-07-01' and '2020-07-31' then quantity * price else 0 end) as july
    from Orders
    left join Product
    using (product_id)
    group by customer_id
)

select customer_id, name
from cte
left join Customers
using (customer_id)
where june >= 100
  and july >= 100;
