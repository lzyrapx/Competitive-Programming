class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int j = 0;
        for(int i = 0; s[i] != '\0'; i++) {
            if((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= '9' && s[i] >= '0')) {
                s[j++] = s[i];
            }
            if(s[i] <= 'Z' && s[i] >= 'A') {
                s[j++] = tolower(s[i]);
            }
        }
        s[j] = '\0';
        for(int i = 0; i <= (j / 2); i++) {
            if(s[i] != s[j - i - 1]) {
                return false;
            }
        }
        return true;
    }
};