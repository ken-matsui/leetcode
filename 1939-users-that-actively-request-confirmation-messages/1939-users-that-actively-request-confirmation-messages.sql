select distinct c1.user_id
from Confirmations c1
left join Confirmations c2
on c1.time_stamp != c2.time_stamp and c1.user_id = c2.user_id
where abs(timestampdiff(second, c1.time_stamp, c2.time_stamp)) <= 86400;
