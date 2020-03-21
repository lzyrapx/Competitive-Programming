/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-21 12:12:44
 */
class Solution {
public:
    // 1 <= n, m <= 50
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>minRow(m, 0);
        for(int i = 0; i < m; i++) {
            minRow[i]= *min_element(matrix[i].begin(),matrix[i].end());
        }
        vector<int>maxCol(n, 0);
        int maxx = 0;
        for(int i = 0; i < n; i++) {
            maxx = matrix[0][i];
            for(int j = 0; j < m; j++) {
                if(matrix[j][i] > maxx) {
                    maxx = matrix[j][i];
                }
            }
            maxCol[i] = maxx;
        }
        vector<int>ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(minRow[i] == maxCol[j]) {
                    ans.push_back(minRow[i]);
                }
            }
        }
        return ans;
    }
};