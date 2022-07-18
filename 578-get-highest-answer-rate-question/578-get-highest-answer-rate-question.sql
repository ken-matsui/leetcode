select question_id as survey_log
from SurveyLog
group by question_id
order by
    (count(case when action = 'answer' then 1 end)
    /
    count(case when action = 'show' then 1 end)) desc,
    question_id
limit 1;
