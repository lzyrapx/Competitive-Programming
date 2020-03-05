/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-05 09:53:40
 */
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        if(mat.size() == 0) {
            return vector<vector<int>>{};
        }
        vector<vector<int>>ans(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                int t = 0;
                for(int r = max(0, i - K); r <= min(i + K, (int)mat.size() - 1); r++) {
                    for(int c = max(0, j - K); c <= min(j + K, (int)mat[0].size() - 1); c++) {
                        t += mat[r][c];
                    }
                }
                ans[i][j] = t;
            }
        }
        return ans;
    }
};