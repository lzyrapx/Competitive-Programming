/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-18 00:25:22
 */
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>>ans;
        int st = 0;
        int ed = 0;
        for(int i = 1; i < S.size(); i++) {
            if(S[i] == S[i - 1]) {
                ed++;
                if(i == S.size() - 1) {
                    if(ed - st + 1 >= 3) {
                        ans.push_back({st, ed});
                    }
                }
            }
            else {
                if(ed - st + 1 >= 3) {
                    ans.push_back({st, ed});
                }
                st = i;
                ed = i;
            }
        }
        return ans;
    }
};