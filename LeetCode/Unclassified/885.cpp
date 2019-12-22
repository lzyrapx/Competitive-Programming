/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-18 00:01:31
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-18 00:01:31
 */
class Solution {
public:
    // 1 <= R <= 100, 1 <= C <= 100
    // 0 <= r0 < R, 0 <= c0 < C
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int r = r0;
        int c = c0;
        int cur_len = 0;
        int idx = 0;
        vector<vector<int>>ans;
        ans.push_back({r, c});
        while(ans.size() < R * C) {
            // 只有向右和向左的时候，步长就加一
            if(idx % 4 == 0 || idx % 4 == 2) {
                cur_len ++;
            }
            // cout << "cur_len = " << cur_len << endl;
            for(int i = 0; i < cur_len; i++) {
                r = r + dir[idx][0];
                c = c + dir[idx][1];
                if(R > r && r >= 0 && C > c && c >= 0) {
                    ans.push_back({r,c});
                }
            }
            idx = (idx + 1) % 4; // change direction
        }
        return ans;
    }
};