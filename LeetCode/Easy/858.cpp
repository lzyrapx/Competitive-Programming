/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-16 09:16:31
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-16 09:16:31
 */
class Solution {
public:
    // 1 <= p <= 1000
    // 0 <= q <= p
    // return 0, 1, 2
    // look as two parallel infinitely long mirrors
    // m * p = n * q
    // m is how many mirror
    // n is how many reflections
    int mirrorReflection(int p, int q) {
        int m = q, n = p;
        while(m % 2 == 0 && n % 2 == 0) {
            m /= 2;
            n /= 2;
        }
        if(m % 2 == 1 && n % 2 == 0) {
            return 2;
        }
        // both odd
        if(m % 2 == 1 && n % 2 == 1) {
            return 1;
        }
        if(m % 2 == 0 && n % 2 == 1) {
            return 0;
        }
        // both even
        return -1;
    }
};