class Solution {
public:
    
   int minimumDeleteSum(string s1, string s2) {
      int m = s1.size();
      int n = s2.size();
      // dp[i][j] 表示 字符串s1[0,i-1]和 s2[0,j-1] 的 删掉字母 最小花费。
      std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
      for(int i=1;i<=m;i++) {
        dp[i][0] = dp[i-1][0] + s1[i-1];
       }
       for(int j=1;j<=n;j++) {
         dp[0][j] = dp[0][j-1] + s2[j-1];
       }
       for(int i = 1;i <= m;i ++)
       {
         dp[i][0] = dp[i-1][0] + s1[i-1];
         for(int j = 1;j <= n;j ++)
         {
           if(s1[i-1] == s2[j-1])
           {
             dp[i][j] = dp[i-1][j-1]; // equal 就不删除
           }
           else{ 
             dp[i][j] = min(dp[i-1][j] + s1[i-1],dp[i][j-1] + s2[j-1]); // 删除 s1[i-1] 或者 删除 s2[j-1]
           }
         }
       }
       return dp[m][n];
    }
};