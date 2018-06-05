class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int>dp(1000,0);
        dp[0] = nums[0];
        dp[1] = max(nums[1],dp[0]);
        dp[2] = max(dp[0] + nums[2],dp[1]);
         for(int i = 3;i < (int)nums.size(); i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[(int)nums.size()-1];
    }
};