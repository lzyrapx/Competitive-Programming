/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-23 01:52:29
 */ 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;
        for(auto& x: nums) {
            mp[x]++;
        }
        for(auto& x: nums) {
            if(mp[x] == 1) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};