select name, sum(amount) as balance
from Transactions
left join Users
using (account)
group by account
having balance > 10000;
