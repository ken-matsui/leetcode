select round(sum(tiv_2016), 2) as tiv_2016
from Insurance
where pid in (
    select distinct i2.pid
    from Insurance i1, Insurance i2
    where i1.pid != i2.pid
      and i1.tiv_2015 = i2.tiv_2015
) and pid not in (
    select distinct i2.pid
    from Insurance i1, Insurance i2
    where i1.pid != i2.pid
      and i1.lat = i2.lat
      and i1.lon = i2.lon
);
