/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-17 21:43:37
 */
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        
        vector<vector<int>>ve(n, vector<int>(m, 0));
        for(int i = 0; i < indices.size(); i++) {
            vector<int>arr = indices[i];
            int x = arr[0];
            int y = arr[1];
            for(int j = 0; j < m; j++) {
                ve[x][j] += 1;
            }
            for(int j = 0; j < n; j++) {
                ve[j][y] += 1;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ve[i][j] % 2 == 1) {
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};