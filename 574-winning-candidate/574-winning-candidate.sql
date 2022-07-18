select name
from (
    select candidateId
    from Vote
    group by candidateId
    order by count(candidateId) desc
    limit 1
) v
left join Candidate
on candidateId = Candidate.id;
