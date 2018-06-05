class Solution {
public:
    // s1 + s2 == s3
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) 
        {
            return false;
        }
        if(s1 + s2 == s3) return true;
        if(s1== s3 || s2 == s3) return true;
        if(s1.size() == 0 && s1.size() == 0 && s3.size() == 0) return true;
        // dp[i][j] 表示字符串s1[0,i] 和 字符串s2[0,j]的交错等于字符串s3
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        
        dp[0][0] = true;
        for(int i = 0 ; i <= s1.size(); i++)
        {
            for(int j = 0; j <= s2.size(); j++)
            {
               if(i == 0 && j == 0) dp[i][j] = true;
               else if(j == 0)
               {
                   if(dp[i - 1][0] == true && s1[i - 1] == s3[i - 1])
                   {
                       dp[i][0] = dp[i - 1][0];
                   }
                   else dp[i][j] = false;
                   
               }
               else if(i == 0)
               {
                   if(dp[0][j - 1] == true && s2[j - 1] == s3[j - 1])
                   {
                        dp[0][j] = dp[0][j - 1];
                   }
                   else dp[i][j] = false;
                   
               }   
               else if(dp[i-1][j] == true && s1[i - 1] == s3[i + j - 1])
               {
                   dp[i][j] = dp[i-1][j];
               }
               else if(dp[i][j-1] == true && s2[j - 1] == s3[i + j - 1])
               {
                   dp[i][j] = dp[i][j-1];
               }
               else dp[i][j] = false;

            }
        }
        return dp[s1.size()][s2.size()];
    }
};