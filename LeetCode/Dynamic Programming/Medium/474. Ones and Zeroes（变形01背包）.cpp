class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        std::vector<std::vector<int> > dp(m+1,std::vector<int>(n+1,0));
        int one_num = 0, zero_num = 0;
        for(auto s :strs)
        {
          one_num = 0, zero_num = 0;
          for(auto c : s) {
            if(c =='1') {
              one_num ++;
            }
            else zero_num  ++;
          }
         // dp[i][j]表示可以组成为 i 个 0 , j 个 1 的最大字符串数
         //必须从顶到底，否则会重复计算
         for(int i = m ; i >= zero_num; --i) {
           for(int j = n; j >= one_num; --j) {
             dp[i][j] = max(dp[i][j],dp[i-zero_num][j-one_num] + 1);
           }
         }
        }
        return dp[m][n];
}
};