class Solution {
public:
// dp[i][j] : through to index is i, sum is j
int findTargetSumWays(vector<int>& nums, int S) {
    int sz = nums.size();
    std::vector<std::vector<int>> dp(2001,std::vector<int>(2001,0));
    dp[0][nums[0] + 1000] = 1;
    dp[0][-nums[0] + 1000] += 1;
    for(int i=1;i < sz;i++) 
    {
      for(int sum = -1000; sum <= 1000;sum ++) 
      {
        if(dp[i-1][sum+1000] > 0) {
          dp[i][sum+1000 + nums[i]] += dp[i-1][sum+1000];
          dp[i][sum+1000 - nums[i]] += dp[i-1][sum+1000];
        }
      }
    }
    if(S > 1000)return 0;
    return dp[sz-1][S+1000];
  }
};