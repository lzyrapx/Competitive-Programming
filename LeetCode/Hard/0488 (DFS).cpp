/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-05 15:58:15
 */
class Solution {
public:
    int findMinStep(string board, string hand) {
        int ans = -1;
        map<char,int>mp;
        for(char ch: hand) {
            mp[ch] += 1;
        }
        ans = dfs(board + "#", mp);
        if(ans == 1e9) {
            return -1;
        }
        return ans;
    }
    int dfs(string s, map<char,int>&mp) {
        // this function can not handle the case below
        // "RRWWRRBBRR"
        // "WB"
        
        // s = removeSubstring(s);
        
        if(s == "#") return 0;
        int res = 1e9;
        for(int i = 0, j = 0; j < s.size(); j++) {
            if(s[i] == s[j]) continue;
            int need = 3 - min(3, j - i);
            if(mp[s[i]] >= need) {
                mp[s[i]] -= need;
                res = min(res, need + dfs(s.substr(0, i) + s.substr(j), mp));
                mp[s[i]] += need;
            }
            i = j;
        }
        return res;
    }
    string removeSubstring(string s) {
        for(int i = 0, j = 0; j < s.size(); j++) {
            if(s[i] == s[j]) continue;
            if(j - i >= 3) {
                return removeSubstring(s.substr(0, i) + s.substr(j));
            }
            else {
                i = j;
            }
        }
        return s;
    }
};