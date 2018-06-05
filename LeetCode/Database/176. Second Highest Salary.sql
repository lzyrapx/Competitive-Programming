# Write your MySQL query statement below

# 选择次大工资
select max(Salary) as SecondHighestSalary from Employee where Salary < (select max(Salary) from Employee);