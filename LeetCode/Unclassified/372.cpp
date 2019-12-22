/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 18:40:52
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 18:40:52
 */
class Solution {
public:
    // b is very large
    // a ^ ( 10 * i + j ) = a ^ j * ( ( a ^ i ) ^ 10 )
    // ( i * mod + x ) * ( j * mod + y ) % mod = x * y % mod
    const int mod = 1337;
    long long qpow(long long a, long long b) {
        long long  ans = 1;
        while(b > 0) {
            if(b & 1) {
                ans = ans * a % mod;
            }
            b >>= 1;
            a = a * a % mod;
        }
        // cout << ans << endl;
        return ans;
    }
    int solve(int a, vector<int>&b, int sz) {
        if(sz == 0) return qpow(a, b[0]) % mod;
        return qpow(a, b[sz]) * qpow(solve(a, b, sz - 1), 10) % mod;
    }
    int superPow(int a, vector<int>& b) {
        if(b.size() == 0) return 1;
        return solve(a, b, b.size() - 1);
        
    }
};