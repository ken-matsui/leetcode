select
    round(
        (
            (
                select count(*) as x
                from Delivery
                where order_date = customer_pref_delivery_date
            )
            /
            count(*)
        ) * 100,
        2
    ) as immediate_percentage
from Delivery;
