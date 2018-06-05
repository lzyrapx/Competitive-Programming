class Solution {
public:
    int strangePrinter(string s) {
        if(s.size() <= 1) return s.size();
        
        //dp[i][j]表示打印出字符串[i, j]范围内字符的最小步数.
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        
        for(int i = 0; i < s.size(); i++ )
        {
            dp[i][i] = 1;
        }
        
        for(int i = s.size() - 1; i >= 0; --i)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(i == j) continue;
                //遍历k之前的初始化，最坏的情况就是加上的是一个不曾出现过的字符s[i]，步数最多加一步.
                dp[i][j] = dp[i+1][j] + 1;
                
                for(int k = i + 1; k <= j; k++) //从i+1位置上的字符开始遍历到 j.
                {
                    if(s[i] == s[k]) 
                    {
                        //如果和i位置上的字符相等，我们就以此位置为界，将[i+1, j]范围内的字符拆为两个部分，
                        //将二者的dp值加起来，和原dp值相比，取较小的那个.
                        dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]);
                    }
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};