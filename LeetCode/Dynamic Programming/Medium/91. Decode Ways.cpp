class Solution {
public:
    int numDecodings(string s) {
        
        int len = s.size();
        if(len == 1 && s[0]=='0')return 0;
        if(len ==0 )return 0;
        //dp[i] 表示以是 以s[i] 开头到结尾的解密方案数,那么dp[i]依赖于dp[i+1] 和dp[i+2];
        vector<int>dp(len+1,0);
        dp[len] = 1;
        
        for(int i = len - 1; i>=0 ; --i) // 倒序遍历
        {
            if(s[i]=='0')dp[i] = 0; // 当前位是 0 不可能独自是一种方案
            else
            {
                dp[i] = dp[i+1]; // 例如 123 , 3 既可以独立存在，也可以和 2 结合，所以 dp[i] = dp[i+1] + dp[i+2]
                if(i < len - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) // 272就不行了
                {
                    dp[i] = dp[i] + dp[i+2]; 
                }
            }
        }
        return dp[0];
        
    }
};