/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-08-01 19:43:08
 */ 
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int,char>mp;
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            mp[indices[i]] = s[i];
        }
        for(int i = 0; i < s.size(); i++) {
            ans = ans + mp[i];
        }
        return ans;
    }
};