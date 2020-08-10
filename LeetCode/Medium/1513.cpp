class Solution {
public:
    // 题意：0-1字符串，问子串都是1的数目是多少个，对1e9+7取模
    // 做法：对每段连续1计算个数，len(s) * (len(s)+1) / 2，最后再求和
    const int mod = 1e9 + 7;
    int numSub(string s) {
        if(s.size() == 0) {
            return 0;
        }
        long long len = 0;
        long long ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                len++;
            } else if(s[i] == '0') {
                long long t = (len * (len + 1) / 2) % mod;
                ans = (ans + t) % mod;
                len = 0;
            }
        }
        long long t = (len * (len + 1) / 2) % mod;
        ans = (ans + t) % mod;
        return ans;
    }
};