class Solution {
public:
    /*
    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.(重复前面的数字或字母0次或以上)
    '*'也可以重复'.'
    */
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        if( lenp == 0 && lens == 0) return true;
        if(s == p) return true;
        
        // dp[i][j] 表示s[0,i) 和 p[0,j)是否匹配。
        
        vector<vector<bool>> dp(s.size() + 1,vector<bool>(p.size() + 1,false));
        
        dp[0][0] = true;
        for(int i = 2; i <= p.size(); i++)
        {
            if(p[i - 1] == '*')
            {
                dp[0][i] = dp[0][i-2]; // *可以消掉c*, a*, b*之类的
            }
        }
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= p.size(); j++)
            {
                if(p[j - 1] == '.' )
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*')
                {
                    // 当*的前一位是'.' , 或者前一位的p等于s时
                    if(p[j - 2] == '.' || s[i - 1] == p[j - 2]) 
                    {
                        //*代表1个(dp[i][j - 1])，*代表多个(dp[i - 1][j])，或者用*消掉c*(dp[i][j - 2])
                        dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2]; 
                    }
                    else 
                    {
                         dp[i][j] = dp[i][j-2];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
        
    }
};