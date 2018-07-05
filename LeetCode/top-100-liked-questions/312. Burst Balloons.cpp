class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        vector<int> a(sz + 2);
        //为了方便计算，将数组扩充一头一尾，值均为1
        a[0] = 1;
        a[sz + 1] = 1;
        for(int i = 0; i < sz ; i++)
        {
            a[i + 1] = nums[i];
        }
        //设dp[i][j]为i到j这段区间所能得到的最大值
        //状态转移方程为dp[i][j] = max(i < k < j) (dp[i][k] + dp[k][j] + a[i] * a[k] * a[j])
        vector<vector<int>>dp(sz + 2, vector<int>(sz + 2, 0));
        for(int len = 2; len < sz + 2; len ++)
        {
            for(int i = 0; i + len < sz + 2; i ++)
            {
                int j = i + len;
                for(int k = i + 1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] + a[i] * a[j] * a[k]);
                }
            }
        }
        return dp[0][sz + 2 - 1];
    }
};