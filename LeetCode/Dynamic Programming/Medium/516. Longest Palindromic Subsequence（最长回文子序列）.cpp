class Solution {
public:
    char str[1234<<1];
    int longestPalindromeSubseq(string s) {

     int len = s.size();
    // dp[i][j]表示字符串i～j下标能构成子串中最长回文子串的长度
     vector<vector<int>>dp(len+1,vector<int>(len+1,0));
        
     for(int i = len - 1; i >= 0; --i)
     {
         dp[i][i] = 1;
         for(int j = i + 1; j < len; j++) 
         {
             if(s[i]==s[j])
             {
                 dp[i][j] = dp[i+1][j-1] + 2;
             }
             else
             {
                 dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
             }
         }
     }
      return dp[0][len-1];
    }

};