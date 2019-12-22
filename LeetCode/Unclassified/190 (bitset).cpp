/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-03 10:34:49
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>bit(n);
        for(int i = 0; i < 32 / 2; i++) {
            bool tmp = bit[i];
            bit[i] = bit[bit.size() - 1 - i];
            bit[bit.size() - 1 - i] = tmp;
        }
        return (uint32_t) bit.to_ulong();
    }
};