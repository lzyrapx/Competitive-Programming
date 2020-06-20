/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-20 21:46:03
 */ 
class Solution {
public:
    // 对于出现三次的数字，各 二进制位 出现的次数都是 3 的倍数。
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int sum = 0;
            for(int j = 0; j < nums.size(); j++) {
                sum += (nums[j] >> i) & 1;
            }
            if(sum % 3 != 0) {
                ans += (1 << i);
            }
        }
        return ans;
    }
};