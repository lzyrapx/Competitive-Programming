class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size() == 0) return -1;
        if(str.size() == 1) return 1;
        map<char,int>mp;
        for(int i = 0; i<str.size();i++)
        {
            mp[str[i]]++;
        }
        for(int i = 0; i < str.size(); i++)
        {
            if(mp[str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};