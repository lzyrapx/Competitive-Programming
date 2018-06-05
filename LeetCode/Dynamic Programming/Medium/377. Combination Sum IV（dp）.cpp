class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,0); // dp[i] = n 表示能最多能分成 n 种的加法组合
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            
            for(int j = 0; j < nums.size(); j ++ ) {
                if(i - nums[j] >= 0) {
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};