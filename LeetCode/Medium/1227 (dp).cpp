/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-21 23:42:39
 */
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) {
            return 1.00000;
        }
        return (1.0 / n + 1.0 * (n - 2) / n * nthPersonGetsNthSeat(n - 1));
    }
};