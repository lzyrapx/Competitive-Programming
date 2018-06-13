class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0) return 0;
        int ans = 0;
        int i = 0;
        while(i < s.size()) {
            if(s[i] == ' ') {
                while(s[i] == ' ' && i < s.size()) i++;
            }
            else
            {
               while(s[i] != ' ' && i < s.size()) i++;
               ans++;
            }
        }
        return ans;
    }
};