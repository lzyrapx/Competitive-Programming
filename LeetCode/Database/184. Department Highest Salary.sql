# Write your MySQL query statement below

# 在两张表中寻找每个部门中工资最高的员工

select  t2.Name as Department, t1.Name as Employee, t1.Salary as Salary from Employee t1, Department t2 
where (t1.DepartmentId = t2.Id and t1.Salary = (select max(Salary) from Employee t3 where t3.DepartmentId = t2.Id) );