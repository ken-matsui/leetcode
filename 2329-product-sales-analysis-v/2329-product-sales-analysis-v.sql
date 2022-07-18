select user_id, sum(quantity * price) as spending
from Sales
left join Product
using (product_id)
group by user_id
order by spending desc, user_id;
