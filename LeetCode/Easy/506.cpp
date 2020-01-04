/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-04 13:31:30
 */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string>ans(nums.size());
        map<int,int,greater<int>>mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        int cnt = 1;
        for(auto x: mp) {
            if(cnt == 1) {
                ans[x.second] = "Gold Medal";
            }
            else if(cnt == 2) {
                ans[x.second] = "Silver Medal";
            }
            else if(cnt == 3) {
                ans[x.second] = "Bronze Medal";
            }
            else {
                ans[x.second] = to_string(cnt);
            }
            cnt++;
        }
        return ans;
    }
};