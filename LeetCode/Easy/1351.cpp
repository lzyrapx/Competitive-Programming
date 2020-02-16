/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-16 19:21:38
 */
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] < 0) cnt++;
            }
        }
        return cnt;
    }
};