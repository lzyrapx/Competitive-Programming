/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-05 23:29:41
 */ 
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            cnt++;
        }
        return n << cnt;
    }
};