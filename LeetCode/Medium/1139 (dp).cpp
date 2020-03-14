/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-14 14:39:42
 */
class Solution {
public:
    // the largest square subgrid that has all 1s on its border
    // 100 * 100
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 1;
        }
        vector<vector<int>>row(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>>col(grid.size(), vector<int>(grid[0].size(), 0));
        if(grid[0][0] == 1) {
            row[0][0] = 1;
            col[0][0] = 1;
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    row[i][j] = 0;
                    col[i][j] = 0;
                }
                else{
                    row[i][j] = (i == 0) ? 1 : row[i - 1][j] + 1;
                    col[i][j] = (j == 0) ? 1 : col[i][j - 1] + 1;
                }
            }
        }
        int l = 0;
        for(int i = grid.size() - 1; i >= 0; --i) {
            for(int j = grid[0].size() - 1; j >= 0; --j) {
                int len = min(row[i][j], col[i][j]);
                while(len > l) {
                    if(row[i][j - len + 1] >= len && col[i - len + 1][j] >= len) {
                        l = len;
                    }
                    len -= 1;
                }
            }
        }
        return l * l;
    }
};