class Solution {
public:
    // Given a non-empty string s, you may delete at most one character. 
    // Judge whether you can make it a palindrome.
    bool validPalindrome(string s) {
        if(s.size() == 1) return true;
        if(s.size() == 0) return false;
        
        for(int i = 0; i < s.size() / 2; i ++) {
             if(s[i] != s[s.size() - i - 1]) {
                 int idx = s.size() - i - 1;
                 return check(s,i + 1, idx) || check(s, i, idx - 1); //删左边一个或删右边一个
             }
        }
        return true;
    }
    bool check(string &s, int i, int j)
    {
       while(i < j) {
           if(s[i] != s[j]) return false;
           i++;--j;
       }
        return true;
    }
};