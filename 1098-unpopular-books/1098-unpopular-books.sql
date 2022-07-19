select book_id, name
from Books
where available_from < date_sub("2019-06-23", interval 1 month)
  and (
      book_id not in (
          select distinct book_id
          from Orders
          where dispatch_date > date_sub('2019-06-23', interval 1 year)
      )
      or
      book_id in (
          select book_id
          from Orders
          where dispatch_date > date_sub('2019-06-23', interval 1 year)
          group by book_id
          having sum(quantity) < 10
      )
  )
