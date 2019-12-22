/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 15:50:18
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 15:50:18
 */
class Solution {
public:
    int smallestRepunitDivByK(int K) { // 1 <= K <= 1e5
        if(K == 1) return 1;
        if(K % 2 == 0) return -1;
        if(K % 5 == 0) return -1;
        int N = 0;
        int len = 0;
        
        while(true) {
            N = N * 10 + 1;
            len++;
            if(N % K == 0) {
                return len;
            }
            N = N % K;
        }
        return -1;
    }
};