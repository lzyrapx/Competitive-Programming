class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return "";
        int st = 0;
        for(int i = 0; i <= s.size(); i++) {
            if(s[i] == ' ' || i == (int)s.size()) {
                reverse(s.begin() + st, s.begin() + i);
                st = i + 1;
            }
        }
        return s;
    }
};