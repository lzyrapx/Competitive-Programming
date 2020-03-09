/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-08 23:49:09
 */
class Solution {
public:
    // 1 <= s.length <= 500
    string sortString(string s) {
        if(s.size() == 0) return 0;
        vector<int>cnt(27, 0);
        set<int>se;
        for(int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            se.insert(s[i] - 'a');
        }
        string ans;
        while(ans.size() != s.size()) {
            string tmp;
            for(auto x: se) {
                if(cnt[x] > 0) {
                    tmp = tmp + char(x + 'a');
                    cnt[x] -= 1;
                }
            }
            ans = ans + tmp;
            tmp.clear();
            for(auto x: se) {
                if(cnt[x] > 0) {
                    tmp = char(x + 'a') + tmp;
                    cnt[x] -= 1;
                }
            }
            ans = ans + tmp;
        }
        return ans;
    }
};