'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-21 15:36:17
'''
class Solution:
    # dp[i][j] 表示有 i + j 人，有 i 个人去了 A，j 个去了 B
    # 答案就是 dp[len(costs) // 2][len(costs) // 2]
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        
        # dp = [[0]*(len(costs) // 2 + 1)]*(len(costs) // 2 + 1)
        dp = [[0 for i in range(len(costs) // 2 + 1)] for j in range(len(costs) // 2 + 1)]
        
        for i in range(1, len(costs) // 2 + 1):
            dp[i][0] = dp[i - 1][0] + costs[i - 1][0]
            
        for j in range(1, len(costs) // 2 + 1):
            dp[0][j] = dp[0][j - 1] + costs[j - 1][1]
            
        for i in range(1, len(costs) // 2 + 1):
            for j in range(1, len(costs) // 2 + 1):
                dp[i][j] = min(dp[i - 1][j] + costs[i + j - 1][0], dp[i][j - 1] + costs[i + j - 1][1])
                
        return dp[len(costs) // 2][len(costs) // 2];
        