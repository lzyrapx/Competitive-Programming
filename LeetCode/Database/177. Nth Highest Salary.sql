CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
set N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      
      select distinct Salary from Employee order by Salary desc limit N , 1 # 跳过前N-1条，选1条
  );
END