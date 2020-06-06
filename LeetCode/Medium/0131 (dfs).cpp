/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-06 17:06:32
 */ 
class Solution {
public:
    // 数据范围不给...
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>subset;
        dfs(res, subset, s);
        return res;
    }
    bool IsPalindrome(string s) {
        return s == string(s.rbegin(), s.rend());
    }
    void dfs(vector<vector<string>>&res, vector<string>&subset, string s) {
        if(s == "") {
            res.push_back(subset);
            return;
        }
        for(int i = 1; i <= s.size(); i++) {
            string tmp = s.substr(0, i);
            if(IsPalindrome(tmp)) {
                subset.push_back(tmp);
                dfs(res, subset, s.substr(i , s.size() - i));
                subset.pop_back();
            }
        }
    }
    
};