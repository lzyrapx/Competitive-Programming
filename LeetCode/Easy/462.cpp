/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-15 16:43:06
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-15 16:43:06
 */
class Solution {
public:
    // 0  <= nums.size() <= 1e5
    // greedy
    int minMoves2(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(auto x : nums) {
            ans += abs(x - nums[nums.size() / 2]);
        }
        return ans;
    }
};