class Solution {
public:
    const int mod = 1e9 + 7;
    int numDecodings(string s) {
        int len = s.size();
        if(s[0] == '0') return 0;
        if(len == 1 && s[0] == '0') return 0;
        if(len == 0) return 0;
        if(len == 1 && s[0] == '*') return 9;
        // dp[i]表示 前 i 个字母能组成的方案数。
        vector<long long    >dp(len + 1, 0);
        dp[0] = 1;
        
        if(s[0] == '*') dp[1] = 9;
        else dp[1] = 1;
        
        for(int i = 2; i <= len; i++)
        {
            if(s[i - 1] == '0')
            {
                if(s[i - 2] == '1' || s[i - 2] == '2')
                {
                    dp[i] += dp[i - 2];
                }
                else if(s[i - 2] == '*') // * 只能等于1 或 2
                {
                    dp[i] += 2LL * dp[i - 2];
                }
            }
            else if(s[i - 1] >= '1' && s[i - 1] <= '9')
            {
                dp[i] += dp[i - 1];
                if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) // 这里和简化版的一样
                {
                    dp[i] += dp[i - 2];
                }
                else if(s[i - 2] == '*')
                {
                    if(s[i - 1] <= '6') // 前面的数字就可以是1或者2了，这时dp[i]需要加上两倍的dp[i-2]
                    {
                        dp[i] += 2LL * dp[i - 2];
                    }
                    else dp[i] += dp[i - 2];
                }
            }
            else if(s[i - 1] == '*')
            {
                dp[i] += 9LL * dp[i - 1]; // 9 种单独拆分选择
                
                if(s[i - 2] == '1') {  // 当前的9种情况都可以跟前面的数字组成两位数： 1*
                    dp[i] += 9LL * dp[i - 2];
                }
                else if(s[i - 2] == '2') // 当前的6种情况都可以跟前面的数字组成两位数： 2*
                {
                    dp[i] += 6LL * dp[i - 2];
                }
                else if(s[i - 2] == '*'){ //是星号，那就是上面两种情况的总和： **
                    dp[i] += ( 9LL * dp[i - 2] + 6LL * dp[i - 2] );
                }
            }
            dp[i] %= mod;
        }
        return dp[len] % mod;
    }
};