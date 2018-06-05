# Write your MySQL query statement below

# 选择至少连续出现三次的数字

select distinct a.Num  as ConsecutiveNums from Logs a, Logs b,Logs c 
where (a.Id = b.Id + 1 and a.Num = b.Num ) and (b.Id = c.Id + 1 and b.Num = c.Num);