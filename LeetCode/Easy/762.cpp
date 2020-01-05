/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 23:59:56
 */
class Solution {
public:
    // R - L will be at most 10000.
    int countPrimeSetBits(int L, int R) {
        auto check = [&](int x) {
            if(x <= 1) return false;
            for(int i = 2; i * i <= x; i++) {
                if(x % i == 0) {
                    return false;
                }
            }
            return true;
        };
        int ans = 0;
        for(int i = L; i <= R; i++) {
            int cnt = 0;
            int x = i;
            while(x > 0) {
                if(x % 2 == 1) {
                    cnt++;
                }
                x /= 2;
            }
            if(check(cnt)) {
                ans++;
            }
        }
        return ans;
    }
};