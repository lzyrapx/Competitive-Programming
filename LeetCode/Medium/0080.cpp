/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-03 23:41:53
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) {
            return nums.size();
        }
        int pos = 1;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] != nums[pos] || nums[i] != nums[pos - 1]) {
                pos++;
            }
            nums[pos] = nums[i];
        }
        return pos + 1;
    }
};