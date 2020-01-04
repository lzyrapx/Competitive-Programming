/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 17:54:19
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = nums.size() - 1; i >= 0; i -= 2) {
            sum += min(nums[i], nums[i - 1]);
        }
        return sum;
    }
};