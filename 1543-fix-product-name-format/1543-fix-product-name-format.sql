select
    lower(trim(product_name)) as product_name,
    date_format(sale_date, "%Y-%m") as sale_date,
    count(product_name) as total
from Sales
group by 1, 2
order by product_name, sale_date;
