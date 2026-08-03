# Write your MySQL query statement below
# Write your MySQL query statement below
with cte as (
    select b.book_id,l.title,l.author,l.genre,l.publication_year,l.total_copies,
        case when return_date is null 
            then count(borrower_name )
        end as current
    from library_books as l
    inner join borrowing_records as b
    on l.book_id= b.book_id  
    group by b.record_id
) select book_id ,title,author, genre ,publication_year ,
    case when total_copies=count(current)  
        then count(current) 
    end as current_borrowers 
from cte 
group by book_id 
having current_borrowers is not null 
order by current_borrowers desc, title 


