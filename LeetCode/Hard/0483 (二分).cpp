/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-05 01:59:11
 */
class Solution {
public:
    // n = 1 + k + k^2 + k^3 + ... + k^(m-1) > k^(m-1)
    // k < n^(1 / (m - 1))
    string smallestGoodBase(string n) {
        long long num = stol(n);
        for(int m = log(num + 1) / log(2); m >= 2; --m) {
            long long left = 2;
            long long right = pow(num, 1. / (m - 1)) + 1;
            while(left < right) {
                long long mid = left + (right - left) / 2;
                long long sum = 0;
                for(int i = 1; i<= m; i++) {
                    sum = 1 + sum * mid;
                }
                if(sum == num) {
                    return to_string(mid);
                }
                if(sum < num) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
        }
        return to_string(num - 1);
    }
};