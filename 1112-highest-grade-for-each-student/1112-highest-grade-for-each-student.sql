with cte as (
    select
        student_id,
        course_id,
        grade,
        rank() over(
            partition by student_id
            order by grade desc, course_id
        ) as rnk
    from Enrollments
)

select student_id, course_id, grade
from cte
where rnk = 1;
