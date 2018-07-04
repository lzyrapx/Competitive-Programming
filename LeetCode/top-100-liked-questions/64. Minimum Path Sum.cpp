class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
     int sz = grid.size();
     int sz1 = grid[0].size();

     vector< vector<int> > dp(sz  , vector<int>(sz1, 0));
     
     dp[0][0] = grid[0][0];

     // std::cout << dp[0][0] << '\n';
     for(int i=1;i<sz1;i++) {
       dp[0][i] = dp[0][i-1] + grid[0][i];
     }
     for(int i=1;i<sz;i++) {
       dp[i][0] = dp[i-1][0] + grid[i][0];
     }
     for(int i=1;i<sz;i++) {
         for(int j=1;j<sz1;j++) {
                dp[i][j] = min(dp[i][j-1] ,dp[i-1][j]) + grid[i][j];
             // std::cout << dp[i][j] << '\n';
         }
     }
     return dp[sz-1][sz1-1];
 }
};