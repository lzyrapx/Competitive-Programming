class Solution {
public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0)return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // cout << m <<" " << n<< endl;
        std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
         if(obstacleGrid[0][0] == 0) dp[0][0] = 1;
            
        for(int i=0;i<m;i++) {
          if(obstacleGrid[i][0] == 0) dp[i][0] = 1;
           else break;
        }
        for(int j=0;j<n;j++) {
          if(obstacleGrid[0][j] == 0)dp[0][j] = 1;
            else break;
        }
        for(int i=1;i<m;i++) {
          for(int j=1;j<n;j++) {
            if(obstacleGrid[i][j]==0) dp[i][j] = dp[i-1][j] + dp[i][j-1]; // dp i , j 表示到 i,j 的路径个数
            else dp[i][j] = 0;
          }
        }
        return dp[m-1][n-1];
    }
};