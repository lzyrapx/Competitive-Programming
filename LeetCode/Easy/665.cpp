/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 15:09:27
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] <= nums[i]) {
                continue;
            }
            int tmp = nums[i - 1];
            nums[i - 1] = nums[i];
            if(is_sorted(nums.begin(), nums.end())) return true;
            nums[i - 1] = nums[i] = tmp;
            if(is_sorted(nums.begin(), nums.end())) return true;
            else return false;
        }
        return true;
    }
};