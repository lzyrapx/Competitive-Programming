/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-03 10:46:39
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32>bit(n);
        return bit.count();
    }
};