class Solution {
public:
    bool checkRecord(string s) {
        if(s.size() <= 1) return true;
        map<char,int>mp;
        int num = 0;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            if(s[i]=='L') num++;
            else num = 0;
            if(num > 2) return false;
            if(mp['A'] >= 2) return false;
        }
        return true;
    }
};