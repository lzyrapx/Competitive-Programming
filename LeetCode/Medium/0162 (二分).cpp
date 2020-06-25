/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-25 23:40:51
 */ 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};