# Write your MySQL query statement below

select t1.Name as Customers  from Customers t1 where t1.Id not in (select t2.CustomerId from Orders t2) 