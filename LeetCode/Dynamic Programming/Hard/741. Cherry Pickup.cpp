class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        if(grid.size() == 0) return 0;
        if(grid.size() == 1) return grid[0][0];
        
        int step = 2 * (grid.size() - 1);
        
        // dp[i][j] 表示走两次走到(i,j) 能获得的最大贡献. 答案就是 dp[n][m].
        vector<vector<int>> dp( grid.size() + 1, vector<int>(grid.size() + 1, -1));
        
        dp[0][0] = grid[0][0];
        for(int s = 1; s <= step; s ++) //枚举总共需要的步数
        {
            vector<vector<int>> now ( grid.size() + 1, vector<int>(grid.size() + 1, -1));
            
            for(int i = 0; i <= s && i < grid.size(); i++) 
            {
                for(int j = 0; j <= s && j < grid.size(); j++)
                {
                    if(grid[i][s - i] < 0 || grid[j][s - j] < 0) continue; // skip thorn
                    
                    int cur = dp[i][j];
                    
                    if(i > 0)
                    {
                      // dp[i][j] = dp[i-1][j];
                       cur = max(cur, dp[i-1][j]);
                    }
                    if(j > 0)
                    {
                        // dp[i][j] = dp[i][j-1];
                        cur = max(cur,dp[i][j-1]);
                    }
                    if( i > 0 && j > 0)
                    {
                        //dp[i][j] = max(dp[i][j],dp[i-1][j-1]); 
                        cur = max(cur , dp[i-1][j-1]);
                    }
                    if(cur < 0) continue;
                    
                    // if i != j , pick cherries at (i, s - i) and (j, s - j ) .
                    // Otherwise, pickup (i, s - i).
                    // 保证 i + s - i = s, j + s - j = s
                    cur += grid[i][s - i] + (i == j ? 0 : grid[j][s - j]);
                    now[i][j] = cur;
                }
            }
            dp = now;
        }
       return max(dp[grid.size() - 1][grid.size() - 1], 0);
    }
};