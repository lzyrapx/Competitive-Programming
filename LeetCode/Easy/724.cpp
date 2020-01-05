/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 20:21:57
 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        vector<int>sum(nums.size(), 0);
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        // special case
        if(sum[sum.size() - 1] - sum[0] == 0) {
            return 0;
        }
        for(int i = 0; i < sum.size() - 1; i++) {
            if(sum[i] == sum[sum.size() - 1] - sum[i + 1]) {
                return i  + 1;
            }
        }
        return -1;
    }
};