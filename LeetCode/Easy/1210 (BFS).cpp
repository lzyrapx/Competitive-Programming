/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-01 22:19:23
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-10-02 00:50:16
 */
class Solution {
public:
    // 2 <= n <= 100, 0 <= grid[i][j] <= 1
    int minimumMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m * n, vector<int>(2, 0));
        queue<pair<int,int>>que;
        
        que.push({1,0});
        vis[1][0] = 1;
        int ans = -1;
        while(!que.empty()) {
            int sz = que.size();
            ans += 1;
            for(int i = 0; i < sz; i++) {
                pair<int,int> cur = que.front();
                que.pop();
                // head
                int x = cur.first / m;
                int y = cur.first % n;
                int dir = cur.second;
                if(x == m - 1 && y == n - 1 && dir == 0) {
                    return ans;
                }
                if(dir == 0) { // horizontal
                    if(y < n - 1 && grid[x][y + 1] == 0) {
                        if(vis[x * n + y + 1][0] == 0) {
                            vis[x * n + y + 1][0] = 1;
                            que.push({x * n + y + 1, 0});
                        }
                    }
                    if(x < m - 1 && grid[x + 1][y - 1] == 0 && grid[x + 1][y] == 0) {
                        if(vis[(x + 1) * n + y][0] == 0) {
                            vis[(x + 1) * n + y][0] = 1;
                            que.push({(x + 1) * n + y, 0});
                        }
                        if(vis[(x + 1) * n + y - 1][1] == 0) {
                            vis[((x + 1) * n + y - 1)][1] = 1;
                            que.push({((x + 1) * n + y - 1), 1});
                        }
                    }
                }
                else if(dir == 1) { // vertical
                    if(x < m - 1 && grid[x + 1][y] == 0) {
                        if(vis[(x + 1) * n + y][1] == 0) {
                            vis[(x + 1) * n + y][1] = 1;
                            que.push({(x + 1) * n + y, 1});
                        }
                    }
                    if(y < n - 1 && grid[x][y + 1] == 0 && grid[x - 1][y + 1] == 0) {
                        if(vis[x * n + y + 1][1] == 0) {
                            vis[x * n + y + 1][1] == 1;
                            que.push({x * n + y + 1, 1});
                        }
                        if(vis[(x - 1) * n + y + 1][0] == 0) {
                            vis[(x - 1) * n + y + 1][0] == 1;
                            que.push({(x - 1) * n + y + 1, 0});
                        }
                    }
                }
            }
        }
        return -1;
    }
};