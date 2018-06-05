# Write your MySQL query statement below
# 选择当天比前一天温度高的ID

select w1.Id from Weather w1, Weather w2
where subdate(w1.Date,1)=w2.Date and w1.Temperature > w2.Temperature;