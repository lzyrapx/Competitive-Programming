/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-25 16:22:07
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int t = nums[0];
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                return nums[i + 1];
            }
        }
        return t;
    }
};