/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-04 18:58:40
 */
class Solution {
public:
    bool check(int x, int y, vector<vector<int>>&M) {
        if(x >= 0 && x < M.size() && y >= 0 && y < M[0].size()) {
            return true;
        }
        return false;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>>ans;
        if(M.size() == 0 || M[0].size() == 0) {
            return ans;
        }
        for(int i = 0; i < M.size(); i++) {
            vector<int>cur;
            for(int j = 0; j < M[0].size(); j++) {
                double total = 0.0, cnt = 0.0;
                for(int x = -1; x <= 1; x++) {
                    for(int y = -1; y <= 1; y++) {
                        if(check(i + x, j + y, M)) {
                            total += M[i + x][j + y];
                            cnt++;
                        }
                    }
                }
                cur.push_back(1.0 * total / cnt);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};