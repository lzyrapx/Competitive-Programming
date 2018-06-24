class Solution {
public:
    int titleToNumber(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return s[0] - 'A' + 1;
        
        int ans = 0;
        for(auto ch : s){
            ans *= 26;
            ans += ch - 'A' + 1;
        }
        return ans;
    }
};