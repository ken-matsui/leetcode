select w2.id
from Weather as w1, Weather as w2
where w1.recordDate = DATE(DATE_ADD(w2.recordDate, INTERVAL -1 DAY))
  and w1.temperature < w2.temperature;
