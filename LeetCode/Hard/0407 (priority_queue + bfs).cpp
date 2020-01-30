/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-30 15:55:29
 */
class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        if(n == 0) {
            return 0;
        }
        int m = heightMap[0].size();
        // first in, smaller out
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    pq.push(make_tuple(heightMap[i][j], i, j));
                    vis[i][j] = 1;
                }
            }
        }
        int ans = 0;
        int maxx = INT_MIN; // 相当于海平面高度
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int h = get<0>(cur);
            int x = get<1>(cur);
            int y = get<2>(cur);
            maxx = max(h, maxx);
            for(int i = 0; i < 4; i++) {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                if(dx >= 0 && dx < heightMap.size() && dy >= 0 && dy < heightMap[0].size() && vis[dx][dy] == 0) {
                    vis[dx][dy] = 1;
                    if(heightMap[dx][dy] < maxx) {
                        ans += (maxx - heightMap[dx][dy]);
                    }
                    pq.push(make_tuple(heightMap[dx][dy], dx, dy));
                }
            }
        }
        return ans;
    }
};