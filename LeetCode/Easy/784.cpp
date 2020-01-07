/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-08 00:41:30
 */
class Solution {
public:
    void dfs(string S, vector<string>&ans, int id) {
        ans.push_back(S);
        if(id >= S.size()) {
            return;
        }
        for(int i = id; i < S.size(); i++) {
            if(isalpha(S[i])) {
                S[i] ^= 32;
                dfs(S, ans, i + 1);
                S[i] ^= 32;
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string>ans;
        dfs(S, ans, 0);
        return ans;
    }
};