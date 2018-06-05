class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        if(m==0)return 0;
        if(m==1)return 1;
        //dp[i] 表示 到 nums[i]前的最大严格上升子序列长度 
        vector<int>dp(m+1,0);
        int ans = 1;
        for(int i = 0; i < m; i++) 
        {
            dp[i] = 1;
            for(int j = 0; j <= i; j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};