select name
from (
    select candidateId, rank() over(order by count(candidateId) desc) as c_rank
    from Vote
    group by candidateId
) v
left join Candidate
on candidateId = Candidate.id
where c_rank = 1;
