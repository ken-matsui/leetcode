select seller_name
from Seller
left join Orders
using (seller_id)
group by seller_id
having count(case when year(sale_date) = 2020 then 1 end) = 0
order by seller_name;
