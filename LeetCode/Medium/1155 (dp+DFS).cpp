/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-14 23:51:54
 */
class Solution {
public:
    int mod = 1e9 + 7;
    // 1 <= d, f <= 30
    int dfs(vector<vector<int>>&dp, int d, int f, int target, int cur_d, int cur_sum) {
        if(cur_d == d && cur_sum == target) {
            return 1;
        }
        if(cur_d == d || cur_sum > target) {
            return 0;
        }
        if(dp[cur_d][cur_sum] != -1) {
            return dp[cur_d][cur_sum];
        }
        int ans = 0;
        for(int i = 1; i <= f; i++) {
            ans = (ans + dfs(dp, d, f, target, cur_d + 1, cur_sum + i) % mod) % mod;
        }
        dp[cur_d][cur_sum] = ans;
        return ans;
        
    }
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>>dp(d + 1, vector<int>(target + 1, -1));
        return dfs(dp, d, f, target, 0, 0);
    }
};