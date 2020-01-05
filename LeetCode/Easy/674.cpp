/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 16:29:37
 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int cnt = 1;
        if(nums.size() == 0) return 0;
        for(int i = 1; i< nums.size(); i++) {
            if(nums[i - 1] < nums[i]) {
                cnt++;
                ans = max(ans, cnt);
            }
            else {
                cnt = 1;
            }
        }
        return ans;
    }
};