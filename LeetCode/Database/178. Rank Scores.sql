# Write your MySQL query statement below

# 按分数从高到低排名，相同分数相同排名
select Score, (select count(distinct Score) from Scores where Score >= s.Score) as Rank
from Scores s
order by s.Score desc;