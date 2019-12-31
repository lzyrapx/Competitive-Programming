/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 22:20:05
 */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        if(nums.size() < 0) return 0;
        sort(nums.begin(),nums.end());
        int ans = 0;
        int p1 = 0;
        int p2 = p1 + 1;
        while(p1 < nums.size() && p2 < nums.size()) {
            if(p1 == p2) {
                p2++;
                continue;
            }
            // 去掉重复的
            if(p1 > 0 && nums[p1] == nums[p1 - 1]) {
                p1++;
                continue;
            }
            auto diff = abs(nums[p1] - nums[p2]);
            if(diff == k) {
                ans++;
                p1++;
                p2++;
            }
            else if(diff < k) {
                p2++;
            }
            else {
                p1++;
            }
        }
        return ans;
    }
};