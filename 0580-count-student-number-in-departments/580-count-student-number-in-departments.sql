select dept_name, count(student_id) as student_number
from Department
left join Student
using (dept_id)
group by dept_id
order by student_number desc, dept_name;
