/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-23 23:25:18
 */
class Solution {
public:
    // leetcode
    // edocteel
    // lcs = 3(eee)
    int lcs(string s, string t) { 
        vector<vector<int>>dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0 ; j < t.size(); j++) {
                if(s[i] == t[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[s.size()][t.size()];
    }
    int minInsertions(string s) {
        if(s.size() <= 1) {
            return 0;
        }
        string t = s;
        reverse(t.begin(), t.end());
        return s.size() - lcs(s, t);
    }
    
};