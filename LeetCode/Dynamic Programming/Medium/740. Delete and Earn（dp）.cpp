class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        
        vector<int> cnt(10001,0);
        for(auto x: nums)
        {
            cnt[x]++;
        }
        //dp[i]表示遍历到i这个数的时候当前情况下的最大值。最后返回dp[10000]的值就是所求
        // dp[0] = 0, dp[1] = cnt[1]。
        //i从2遍历到10000。对于dp[i]，因为如果要了i这个数就不能要i-1和i+1/
        //所以当前i有两个选择：一，要i这个数带来的分数 cnt[i] * i，那就不能要dp[i-1]只能要dp[i-2]。
        //二，不要i带来的分数要dp[i-1]的分数。这两个选择取最大值
        //所以dp[i] = max(dp[i-1], cnt[i] * i + dp[i-2])，最后返回dp[10000]
        vector<int>dp(10001,0);
        dp[1] = cnt[1] * 1;
        
        for(int i = 2;i <= 10000 ; i++)
        {
            dp[i] = max(dp[i - 1] , cnt[i] * i + dp[i - 2]);
        }
        return dp[10000];
    }
};