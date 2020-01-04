/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-28 21:56:37
 */
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int>res(S.size(), S.size());
        int pos = -1e9;
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == C) {
                pos = i;
            }
            res[i] = min(res[i], abs(i - pos));
        }
        for(int i = S.size() - 1; i >= 0; --i) {
            if(S[i] == C) {
                pos = i;
            }
            res[i] = min(res[i], abs(i - pos));
        }
        return res;
    }
};