class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0) return 0;
        map<char,int>mp{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        for(int i = 0; i < s.size();i++)
        {
            int val = mp[s[i]];
            if(i == s.size() -1 || (mp[s[i]] >= mp[s[i+1]])) ans += val;
            else ans -= val;
        }
        return ans;
    }
};
