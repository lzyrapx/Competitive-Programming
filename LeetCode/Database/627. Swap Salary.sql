# Write your MySQL query statement below

# 将性别反转
update salary set sex =  case sex
when 'm' then 'f'
else 'm' end;
