/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-27 15:52:33
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>ve(26);
        for(char c: s){
            ve[c - 'a']++;
        }
        vector<bool>vis(26);
        string ans;
        for(int i = 0; i < s.size(); i++) {
            ve[s[i] - 'a']--;
            if(vis[s[i] - 'a']) {
                continue;
            }
            while(!ans.empty() && s[i] < ans.back() && ve[ans.back() - 'a']) {
                vis[ans.back() - 'a'] = false;
                 ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i] - 'a'] = true;
        }
        return ans;
    }
};