class Solution {
public:
    const int mod = 1e9+7;
    int countPalindromicSubsequences(string S) {
        if(S.size()==0)return 0;
        //dp[i][j]表示字符串[i,j]中的不同回文子序列的个数.
        
        vector<vector<long long>> dp(S.size(),vector<long long>(S.size(),0));
        
        for(int i = 0; i < S.size(); i++)
        {
            dp[i][i] = 1; // 单个字母
        }
        for(int len = 1; len < S.size();len++)
        {
            for(int i = 0; i < S.size() - len; i++)
            {
                int j = i + len;
                if(S[i] != S[j]) // "abcd" 即， a != d
                {
                    // "abcd" = " "abc" + "bcd" - "bc"
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }
                
                // https://www.cnblogs.com/grandyang/p/7942040.html
                
                //需要分情况讨论，因为我们不知道中间还有几个和S[i]相等的值
                //比如"aba"和"aaa"
                //当i = 0, j = 2的时候，两个字符串均有S[i] == S[j]，此时二者都新增两个子序列"a"和"aa"，
                //但是"aba"中间的"b"就可以加到结果res中，而"aaa"中的"a"就不能加了,因为和外层的单独"a"重复了.
                
                else if(S[i] == S[j]) 
                {
                    int left = i + 1 , right = j - 1;
                    while(left <= right && S[left] != S[i]) left++;
                    while(left <= right && S[right] != S[i]) right--;
                    
                    if(left > right)//中间没有和S[i]相同的字母
                    {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    }
                    else if(left == right) //中间只有一个和S[i]相同的字母
                    {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    }
                    else if(left < right) //中间至少有两个和S[i]相同的字母
                    {
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1];
                    }
                }
                dp[i][j] = (dp[i][j] + mod) % mod;
                dp[i][j] %= mod;
            }
        }
        return dp[0][S.size() - 1] % mod;
    }
};