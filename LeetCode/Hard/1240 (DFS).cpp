/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-30 16:37:05
 */
class Solution {
public:
    // 每一次 dfs 必须要搜出一个正方形
    // 1 <= n <= 13
    // 1 <= m <= 13
    bool dfs(vector<vector<int>>&vis, int step, int area, int n, int m, int k) {
        if(area == n * m) return true;
        if(step > k) return false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 1) continue;
                for(int l = 0; i + l < n && j + l < m && vis[i][j + l] == 0; l++) {
                    for(int x = 0; x <= l; x++) {
                        for(int y = 0; y <= l; y++) {
                            vis[i + x][j + y] = 1;
                        }
                    }
                    if(dfs(vis, step + 1, area + (l + 1) * (l + 1), n, m, k)) {
                        return true;
                    }
                    // backtracking
                    for(int x = 0; x <= l; x++) {
                        for(int y = 0; y <= l; y++) {
                            vis[i + x][j + y] = 0;
                        }
                    }
                }
                return false;
            }
        }
        return false;
    }
    int tilingRectangle(int n, int m) {
        vector<vector<int>>vis(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; ;i++) {
            if(dfs(vis, 1, 0, n, m, i)) {
                return i;
            }
        }
    }
};