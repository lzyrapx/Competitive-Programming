/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-10 18:10:03
 */
class Solution {
public:
    
    // If you can't cut off all the trees, output -1 in that situation.
    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int>>pos;
        int n = forest.size();
        int m = forest[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(forest[i][j] > 1) {
                    pos.push_back({forest[i][j], i, j});
                }
            }
        }
        sort(pos.begin(), pos.end(), [](vector<int>&a, vector<int>&b) {
           return a[0] < b[0]; 
        });
        
        int ans = 0;
        int r = 0;
        int c = 0;
        for(auto x: pos) {
            int dis = bfs(r, c, x[1], x[2], forest);
            if(dis < 0) {
                return -1;
            }
            ans += dis;
            r = x[1];
            c = x[2];
            forest[x[1]][x[2]] = 1;
        }
        return ans;
    }
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // BFS to find shortest path to next tree
    // if cannot reach next tree, return -1
    int bfs(int sr, int sc, int r, int c, vector<vector<int>>&forest) {
        int n = forest.size();
        int m = forest[0].size();
        queue<pair<int,int>>que; // vector<int> 换成 pair<int,int> 就不 TLE 了？？？
        vector<vector<int>>vis(n, vector<int>(m, 0));
        que.push({sr, sc});
        vis[sr][sc] = 1;
        int step = 0;
        while(!que.empty()) {
            int sz = que.size();
            for(int t = 1; t <= sz; t++) {
                int cur_r = que.front().first;
                int cur_c = que.front().second;
                que.pop();
                if(cur_r == r && cur_c == c) return step;
                for(int i = 0; i < 4; i++) {
                    int nr = cur_r + dir[i][0];
                    int nc = cur_c + dir[i][1];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && forest[nr][nc] > 0 && vis[nr][nc] == 0)
                    {
                        vis[nr][nc] = 1;
                        que.push({nr,nc});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};