select SalesPerson.name
from SalesPerson
where SalesPerson.sales_id not in (
    select Orders.sales_id
    from Orders
    left join Company
    on Orders.com_id = Company.com_id
    where Company.name = 'RED'
);
