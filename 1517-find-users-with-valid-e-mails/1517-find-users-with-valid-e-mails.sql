select *
from Users
where mail regexp '^[a-z][a-z0-9._-]*@leetcode\\.com';
