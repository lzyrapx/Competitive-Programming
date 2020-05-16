/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-17 00:23:01
 */ 
class Solution {
public:
    // size: [1, 50].
    int containVirus(vector<vector<int>>& grid) {
        int ans = 0;
        while(true) {
            int walls = solve(grid);
            if(walls == 0) { // 没有更多的墙可以建了
                break;
            }
            ans += walls;
        }
        return ans;
    }
    int dir[4][2] = {{1,0},{-1,0},{0, 1}, {0, -1}};
    int solve(vector<vector<int>>&grid) {
        int m = grid.size();
        int n = grid[0].size();
        // cnt is max area to be affected by a single virus region
        // ans is corresponding walls
        int cnt = 0, ans = 0, color = -1, row = -1, col = -1;
        // visited virus as 1, visited 0 using different color to indicate being affected by different virus
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // 先算出感染面积最大的情况。
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    int walls = 0;
                    int area = dfs(grid, vis, i, j, color, walls);
                    if(area > cnt) {
                        ans = walls;
                        cnt = area;
                        row = i;
                        col = j;
                    }
                    color -= 1;
                }
            }
        }
        build_walls(grid, row, col);
        vis = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    spread(grid, vis, i, j);
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int raw, int col, int color, int& walls) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        // 越界
        if(raw < 0 || raw >= m || col < 0 || col >= n) return 0;
        // 可以感染
        if(grid[raw][col] == 0) {
            walls += 1;
            if(vis[raw][col] == color) { // 已经被当前病毒感染过了
                return 0;
            }
            vis[raw][col] = color;
            return 1;
        }
        // 当前没有被遍历过和必须有病毒
        if(vis[raw][col] == 1 || grid[raw][col] != 1) {
            return 0;
        }
        vis[raw][col] = 1;
        for(int i = 0; i < 4; i++) {
            int nr = raw + dir[i][0];
            int nc = col + dir[i][1];
            ans += dfs(grid, vis, nr, nc, color, walls);
        }
        return ans;
    }
    void build_walls(vector<vector<int>>&grid, int raw, int col) {
        int m = grid.size();
        int n = grid[0].size();
        // 越界
        if (raw < 0 || raw >= m || col < 0 || col >= n) return;
        // 建墙围住当前病毒
        if(grid[raw][col] != 1) return;
        
        grid[raw][col] = -1;
        for(int i = 0; i < 4; i++) {
            int nr = raw + dir[i][0];
            int nc = col + dir[i][1];
            build_walls(grid, nr, nc);
        }
    }
    void spread(vector<vector<int>>&grid, vector<vector<int>>& vis, int raw, int col) {
        int m = grid.size();
        int n = grid[0].size();
        // 越界
        if (raw < 0 || raw >= m || col < 0 || col >= n) return;
        // 被遍历过
        if(vis[raw][col] == 1) return;
        // 可以感染
        if(grid[raw][col] == 0) {
            grid[raw][col] = 1;
            vis[raw][col] = 1;
            return;
        }
        if(grid[raw][col] == 1) {
            vis[raw][col] = 1;
            for(int i = 0; i < 4; i++) {
                int nr = raw + dir[i][0];
                int nc = col + dir[i][1];
                spread(grid, vis, nr, nc);
            }
        }
    }
};