select
    s.student_id,
    s.student_name,
    sub.subject_name,
    (
        select count(*)
        from Examinations e2
        where s.student_id = e2.student_id
          and sub.subject_name = e2.subject_name
    ) as attended_exams
from Students s, Subjects sub
group by s.student_id, sub.subject_name
order by s.student_id, sub.subject_name;
