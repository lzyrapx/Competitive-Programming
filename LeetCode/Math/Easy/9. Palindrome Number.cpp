class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        string s = to_string(x);
        return s == string(s.rbegin(),s.rend());
    }
};