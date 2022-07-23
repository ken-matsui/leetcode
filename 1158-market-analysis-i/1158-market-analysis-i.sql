select
    user_id as buyer_id,
    join_date,
    count(order_id) as orders_in_2019
from Users
left join Orders
on year(Orders.order_date) = 2019
and Users.user_id = Orders.buyer_id
group by user_id;
