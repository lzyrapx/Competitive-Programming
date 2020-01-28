/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-27 22:20:16
 */
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxReach = 0;
        int ans = 0;
        for(int i = 0; maxReach < n;) {
            if(i < nums.size() && nums[i] <= (maxReach + 1)) {
                maxReach = maxReach + nums[i];
                i++;
            }
            else {
                maxReach = maxReach + maxReach + 1;
                ans++;
            }
        }
        return ans;
    }
};