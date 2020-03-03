/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-03 20:51:08
 */
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans;
        if(nums.size() == 0) {
            return ans;
        }
        vector<int>tmp = nums;
        sort(tmp.begin(), tmp.end());
        unordered_map<int,int>mp;
        for(int i = 0; i < tmp.size(); i++) {
            if(mp[tmp[i]] > 0) continue;
            mp[tmp[i]] = i + 1;
        }
        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(mp[nums[i]] - 1);
        }
        return ans;
    }
};