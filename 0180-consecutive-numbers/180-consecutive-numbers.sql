select distinct num as ConsecutiveNums
from (
    select
        lag(num) over() as lag_num,
        num,
        lead(num) over() as lead_num
    from Logs
) n
where lag_num = num
  and num = lead_num;
