class Solution {
public:
    typedef long long ll;
    int splitArray(vector<int>& nums, int m) {
        int sz = nums.size();
        if(sz == m) {
            ll ans = 0;
            for(auto x :nums)
            {
               ans = max(ans,1LL*x);
            }
            return ans;
        }
        if(m == 1) {
            ll ans = accumulate(nums.begin(),nums.end(),0);
            return ans;
        }
        vector<vector<int>> dp(m+1,vector<int>(sz+1,INT_MAX)); //初始化为整型最大值，如果无法分为i组，那么还是保持为整型最大值

        /*
         dp[i][j]表示将数组中前j个数字分成i组所能得到的最小的各个子数组中最大值
         dp[i-1][k]表示数组中前k个数字分成i-1组所能得到的最小的各个子数组中最大值，
         sums[j]-sums[k]就是后面的数字之和，我们取二者之间的较大值，
         然后和dp[i][j]原有值进行对比，更新dp[i][j]为二者之中的较小值，这样k在[i-1, j-1]的范围内扫过一遍。
         dp[i][j]就能更新到最小值，我们最终返回dp[m][sz]即可。
        */
        
        vector<int>sum(sz+1,0);
        
        dp[0][0] = 0;
        for(int i = 1; i <= sz; i++)
        {
            sum[i] = sum[i-1] + nums[i-1];
        }
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= sz; j++)
            {
                for(int k = i - 1; k < j ; k++)
                {
                    dp[i][j] = min(dp[i][j],max(dp[i - 1][k] , sum[j] - sum[k]));
                }
            }
        }
        return dp[m][sz];
    }
};