/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-17 21:56:49
 */
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ve = grid;
        int n = grid.size();
        int m = grid[0].size();
        while(k--) {
            int t = ve[0][0];
            ve[0][0] = ve[n - 1][m - 1];
            for(int j = 1; j < m; j ++) {
                swap(ve[0][j], t);
            }
            for(int i = 1; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    swap(ve[i][j], t);
                }
            }
        }
        return ve;
    }
};