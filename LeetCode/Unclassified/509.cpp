/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-05 22:33:23
 */
class Solution {
public:
    int fib(int N) {
        if(N == 0) return 0;
        int a = 0, b = 1;
        for(int i = 2; i<= N; i++) {
            int c = b;
            b = a + b;
            a = c;
        }
        return b;
    }
};