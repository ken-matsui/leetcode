select
    Prices.product_id,
    round(sum(units * price) / sum(units), 2) as average_price
from Prices, UnitsSold
where Prices.product_id = UnitsSold.product_id
  and purchase_date between start_date and end_date
group by Prices.product_id;
