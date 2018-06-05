class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

        int sz = A.size();
        if(sz <= 2) return 0;
        int ans = 0;
        // dp[i][j] 表示以 i 为 结尾，j 为公差差的等差数列
        vector<map<long long,int>> dp(sz + 1);
        // int max_diff = 0;
        for(int i = 0; i < sz; i++)
        {
            for(int j = 0; j < i; j++)
            {
                long long diff = 1LL * A[i] - 1LL * A[j];
                // max_diff = max(max_diff,diff);
                if(dp[j].count(diff) > 0)
                {
                    dp[i][diff] += dp[j][diff] + 1;
                }
                else
                {
                    dp[i][diff] += 1;
                }
            }
            // 对于以当前为结尾，每个diff组成的数列个数相加
           // for(int j = 0; j <= max_diff; j++)
            for(auto diff : dp[i])
            {
                ans += diff.second;
            }
            //减掉长度为2的
            ans -= i;
        }
        return ans;
    }
};