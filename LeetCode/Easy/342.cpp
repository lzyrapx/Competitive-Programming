/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-02 13:15:33
 */
class Solution {
public:
    // 4^n = 2^2^n
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        if((num & (num - 1)) == 0 && (num & 0x55555555) != 0) return true;
        return false;
    }
};