/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-03 22:56:39
 */ 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return false;
        }
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                return true;
            }
            // [1,1,3,1,1] or [3,3,1,3,3]
            if(nums[low] == nums[mid] && nums[high] == nums[mid]) {
                low++;
                high--;
            } else if(nums[mid] >= nums[low]) { // mid 左端升序
                if(target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            } else { // mid 右端降序
                if(target <= nums[high] && target > nums[mid]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};