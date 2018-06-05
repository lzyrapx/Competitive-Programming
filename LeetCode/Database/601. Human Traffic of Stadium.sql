# Write your MySQL query statement below

# 选择人数连续三次超过100的行

select * from stadium a
where a.people >= 100
and ( ( a.id + 1 in (select id from stadium where people >= 100) and (a.id + 2 in (select id from stadium where people >= 100) ) )
or ( (a.id - 1  in (select id from stadium where people >= 100) and (a.id + 1 in (select id from stadium where people >= 100) ) ) )
or ( (a.id - 2  in (select id from stadium where people >= 100) and (a.id - 1 in (select id from stadium where people >= 100) ) ) ) 
);