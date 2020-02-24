/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-17 00:46:02
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < n; k++) {
                        if(matrix[k][j] != 0) {
                            matrix[k][j] = 1e9;
                        }
                    }
                    for(int k = 0; k < m; k++) {
                         if(matrix[i][k] != 0) {
                            matrix[i][k] = 1e9;
                        }
                    }
                    matrix[i][j] = 1e9;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 1e9) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};