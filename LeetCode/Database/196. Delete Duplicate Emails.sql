# Write your MySQL query statement below

# 删除重复那一行
delete t1 from Person t1 , Person t2 where (t1.Id > t2.Id and t1.Email = t2.Email);