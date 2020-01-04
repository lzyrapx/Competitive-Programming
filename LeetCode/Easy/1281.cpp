/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-22 15:10:39
 */
class Solution {
public:
    int subtractProductAndSum(int n) {
        long long prod = 1;
        long long sum = 0;
        int rem = 0;
        while(n > 0) {
            rem = n % 10;
            prod *= rem;
            sum += rem;
            n /= 10;
        }
        return prod - sum;
    }
};