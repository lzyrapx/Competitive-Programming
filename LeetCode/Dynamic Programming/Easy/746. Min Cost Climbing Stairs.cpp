class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(10000,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        cost[cost.size()] = cost[cost.size()+1] = 0;
        int ans = 0;
        for(int i = 0; i < (int)cost.size()-1; i++) {
            dp[i+2] = min(dp[i],dp[i+1]) + cost[i+2];
        }
        return dp[cost.size()];
      }
};