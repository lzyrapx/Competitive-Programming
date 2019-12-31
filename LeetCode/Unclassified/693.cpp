/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 18:03:01
 */
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastBit = -1;
        while(n > 0) {
            int bit = n % 2;
            n /= 2;
            if(bit == lastBit) {
                return false;
            }
            lastBit = bit;
        }
        return true;
    }
};