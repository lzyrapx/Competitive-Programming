# Write your MySQL query statement below

# 这题有点复杂，大概是筛选和计算概率

select Request_at as Day, 
round( count( if ( Status <> 'completed',true,NULL) ) / count(*), 2) as 'Cancellation Rate' from Trips #注意这里必须是NULL
where (Request_at between '2013-10-01' and '2013-10-03')
and Client_id not in (select Users_Id from Users where Banned = 'Yes')
group by Request_at;