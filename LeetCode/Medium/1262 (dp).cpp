/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-14 22:28:28
 */
class Solution {
public:
    // 1 <= nums.length <= 4 * 10^4
    int maxSumDivThree(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0] % 3 ? 0 : 1;
        }
        vector<int>dp(3,0);
        for(int i = 0; i < nums.size(); i++) {
            vector<int>tmp = dp;
            for(auto x: dp) {
                int cur = x + nums[i];
                tmp[cur % 3] = max(tmp[cur % 3], cur);
            }
            dp = tmp;
        }
        return dp[0];
    }
};