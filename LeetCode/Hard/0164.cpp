/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-25 20:58:31
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            ans = max(ans, nums[i + 1] - nums[i]);
        }
        return ans;
    }
};