/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-03 14:31:33
 */
class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        while(b != 0) {
            sum = a ^ b;
            b = (unsigned int)(a & b) << 1;
            a = sum;
        }
        return sum;
    }
};