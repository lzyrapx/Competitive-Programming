/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-15 14:42:47
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-15 14:43:38
 */
class Solution {
public:
    // 1 <= n <= INT_MAX
    int integerReplacement(long long n) { // change int to long long
        if(n == 1) return 0;
        if(n % 2 == 0) {
            return integerReplacement(n / 2) + 1;
        }
        else {
            return min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1;
        }
    }
};