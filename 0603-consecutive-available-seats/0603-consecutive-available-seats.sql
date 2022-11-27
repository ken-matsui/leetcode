select distinct c1.seat_id
from Cinema c1, Cinema c2
where abs(c1.seat_id - c2.seat_id) = 1
  and c1.free = true
  and c2.free = true
order by c1.seat_id;
