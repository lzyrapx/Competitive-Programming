# Write your MySQL query statement below
SELECT 
	it.id AS id, 
	d1.revenue AS Jan_Revenue, 
	d2.revenue AS Feb_Revenue, 
	d3.revenue AS Mar_Revenue,
	d4.revenue AS Apr_Revenue,
	d5.revenue AS May_Revenue,
	d6.revenue AS Jun_Revenue,
	d7.revenue AS Jul_Revenue,
	d8.revenue AS Aug_Revenue,
	d9.revenue AS Sep_Revenue,
	d10.revenue AS Oct_Revenue,
	d11.revenue AS Nov_Revenue,
	d12.revenue AS Dec_Revenue
FROM (SELECT DISTINCT(id) AS id FROM Department ORDER BY id) AS it
 LEFT JOIN Department AS d1 ON d1.month = 'Jan' AND d1.id = it.id
 LEFT JOIN Department AS d2 ON d2.month = 'Feb' AND d2.id = it.id
 LEFT JOIN Department AS d3 ON d3.month = 'Mar' AND d3.id = it.id
 LEFT JOIN Department AS d4 ON d4.month = 'Apr' AND d4.id = it.id
 LEFT JOIN Department AS d5 ON d5.month = 'May' AND d5.id = it.id
 LEFT JOIN Department AS d6 ON d6.month = 'Jun' AND d6.id = it.id
 LEFT JOIN Department AS d7 ON d7.month = 'Jul' AND d7.id = it.id
 LEFT JOIN Department AS d8 ON d8.month = 'Aug' AND d8.id = it.id
 LEFT JOIN Department AS d9 ON d9.month = 'Sep' AND d9.id = it.id
 LEFT JOIN Department AS d10 ON d10.month = 'Oct' AND d10.id = it.id
 LEFT JOIN Department AS d11 ON d11.month = 'Nov' AND d11.id = it.id
 LEFT JOIN Department AS d12 ON d12.month = 'Dec' AND d12.id = it.id
ORDER BY it.id
;