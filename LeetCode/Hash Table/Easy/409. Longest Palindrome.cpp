class Solution {
public:
    int longestPalindrome(string s) {
        int map[256] = {0};
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]-'A'] == 0) map[s[i]-'A'] = 1;
            else {
                map[s[i]-'A']++;
                if (map[s[i]-'A'] == 2) {
                    ans += 2;
                    map[s[i]-'A'] = 0;
                }
            }   
        }    
        if (ans < s.size()) ans++;
        return ans;
    }
};