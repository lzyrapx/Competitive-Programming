class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        grid[x][y] = '0';
        // 边界条件放后面会RE
        if(x - 1 >= 0 && grid[x - 1][y] == '1' ) {
            dfs(grid, x - 1, y);
        }
        if(y - 1 >= 0 && grid[x][y - 1] == '1') {
            dfs(grid, x , y - 1);
        }
        if(x + 1 < (int)grid.size() && grid[x + 1][y] == '1' ) {
            dfs(grid, x + 1, y);
        }
        if(y + 1 < (int)grid[0].size() && grid[x][y + 1]== '1' ) {
            dfs(grid, x , y + 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                if(grid[i][j] == '1') {
                    ans ++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};