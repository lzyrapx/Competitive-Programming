/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-01 22:57:16
 */ 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};