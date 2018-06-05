class Solution {
public:
    /*
    从给定的一个长度为n的数组中，找出3个互不重叠的长度为k的子数组，使这3个数组的和最大。
    若有多组解，取最小下标的那组解。
    */
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
       int sz = nums.size();
       if(sz == 0) return vector<int>();
        int l = nums.size() - k + 1;
        vector<int> sum(sz + 1, 0);
        
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < k; j++)
            {
                sum[i] += nums[i + j]; // sum[i] 是以nums[i]开头的 k 个数的和
            }
        }
        
        // dp[i][j] = maximun sum of previous j sums of number i  
        vector<vector<int>> dp(3,vector<int>(sz + 1, 0));
              
        // 0
         dp[0][0] = sum[0];
        for(int i = 1; i < l; i++)
        {
            dp[0][i] = max(dp[0][i-1],sum[i]);
        }
        
        // 1
        dp[1][k] = sum[0] + sum[k];
        for(int i = 1 + k; i < l ;i ++)
        {
            dp[1][i] = max(dp[1][i - 1],dp[0][i - k] + sum[i]);
        }
        
        // 2
        dp[2][k + k] = sum[0] + sum[k] + sum[k + k];
        for(int i = 1 + k + k; i < l; i++)
        {
            dp[2][i] = max(dp[2][i - 1], dp[1][i - k] + sum[i]);
        }
        
        vector<int>ans(3,0);
        
        int maxx , pos;
        int limit = l;
        //找最小下标:从第三行开始到第一行，找存着最大数的最小下标即可
        //注意第二行第一行的下标上限是高一行的最小下标减去 k
        for(int i = 2; i >= 0; --i)
        {
            maxx = pos = 0;
            for(int j = 0; j < limit; j++)
            {
                if(dp[i][j] > maxx)
                {
                    maxx = dp[i][j];
                    pos = j;
                }
            }
            ans[i] = pos;
            limit = pos - k + 1;
        }
        return ans;
    }
};