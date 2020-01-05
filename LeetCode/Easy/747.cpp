/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 23:05:18
 */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        map<int,int>mp;
        int maxx = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
            maxx = max(maxx, nums[i]);
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != maxx && maxx < nums[i] * 2) {
                return -1;
            }
        }
        return mp[maxx];
    }
};