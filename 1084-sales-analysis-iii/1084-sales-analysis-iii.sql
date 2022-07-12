select distinct Product.product_id, product_name
from Sales
left join Product
on Sales.product_id = Product.product_id
where Sales.sale_date between '2019/01/01' and '2019/03/31'
  and Product.product_id not in (
      select product_id
      from Sales
      where sale_date not between '2019/01/01' and '2019/03/31'
  );
