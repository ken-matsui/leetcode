with cte as (
    select
        question_id,
        count(case when action = 'answer' then 1 end)
        /
        count(case when action = 'show' then 1 end)
        as answer_rate
    from SurveyLog
    group by question_id
    order by answer_rate desc, question_id
)

select question_id as survey_log
from cte
limit 1;
