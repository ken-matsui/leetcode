select id, year, ifnull(npv, 0) as npv
from Queries
left join NPV
using (id, year);
