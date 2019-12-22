/*
 * @Descripttion: Prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-11 09:23:22
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-11 09:23:22
 */
class Solution {
public:
    // N = 5 = 101
    // 101 ^ 001(1) = 100
    // 100 ^ 010(2) = 110
    // 110 ^ 100(4) = 010
    int bitwiseComplement(int N) {
        if(N  == 0) return 1;
        for(int i = N, pos = 0; i > 0; i /= 2, pos ++) {
            N ^= (1 << pos);
        }
        return N;
    }
};