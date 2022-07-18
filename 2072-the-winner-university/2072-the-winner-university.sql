select
    case
        when ncnt > ccnt then 'New York University'
        when ncnt < ccnt then 'California University'
        else 'No Winner'
    end as winner
from (
    select count(student_id) as ncnt
    from NewYork
    where score >= 90
) n
cross join
(
    select count(student_id) as ccnt
    from California
    where score >= 90
) c;
