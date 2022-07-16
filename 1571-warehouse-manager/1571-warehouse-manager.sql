select
    name as warehouse_name,
    sum((Width * Length * Height) * units) as volume
from Warehouse
left join Products
using (product_id)
group by name;
