/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-09 01:03:02
 */
class Solution {
public:
    // costs.length == 3
    // days is in strictly increasing order.
    // 1 <= days.length <= 365
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if(days.size() == 1) {
            return costs[0];
        }
        vector<int>dp(366, 0);
        dp[0] = 0;
        for(auto x: days) {
            dp[x] = costs[0];
        }
        for(int i = 1; i <= 365; i++) {
            if(dp[i] == 0) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = dp[i - 1] + costs[0];
                dp[i] = min(dp[i], dp[max(0,i - 7)] + costs[1]);
                dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
            }
        }
        return dp[365];
    }
};