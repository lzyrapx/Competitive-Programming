class Solution {
public:
    /*
    L = s[0] + s[1] * K + s[2] * K^2 + ... + s[n-1] * K^(n-1)
    R = s[0] * K^(n-1) + s[1] * K^(n-2) + ... + s[n-1]
    if they are the same, then s[0..n-1] is very likely a palindrome.
    */
    string shortestPalindrome(string s) {
        if(s.size() == 0) return "";
        if(s.size() == 1) return s;
        int mod = 1e9+7;
        int fact = 17;
        int maxlen = 1; //最大回文长度
        long long extralen = 0; // 需要额外的字符
        long long hash_left = 0;
        long long hash_right = 0;
        long long prod = 1;
        for(int i = 0; i < s.size(); i++) {
            hash_left = ((hash_left * fact) % mod + s[i]) % mod;
            hash_right = (hash_right + prod * s[i]) % mod;
            // cout << hash_left << " " << hash_right << endl;
            prod = (prod * fact) % mod;
            if(hash_left == hash_right) { // hash相同表示0~i是回文串
                maxlen = i + 1;
            }
        }
        string ans;
        extralen = s.size() - maxlen;
        for(int i = 0 , j = s.size() - 1; i < extralen; i++, j--)
        {
            ans += s[j];
        }
        ans += s;
        
        return ans;
    }
    
};