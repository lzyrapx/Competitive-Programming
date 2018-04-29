class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n == 0) return str;
        if(str.size() <= 1) return str;
        n = n % str.size();
        string a = str.substr(0,n);
        string b = str.substr(n);
        return b + a;
    }
};