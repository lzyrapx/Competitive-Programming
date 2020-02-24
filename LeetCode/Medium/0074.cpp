/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-17 01:08:58
 */
class Solution {
public:
    // 不想写二分。。。
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) {
            return false;
        }
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};