/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-21 18:06:24
 */ 
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        for(int i = 0; i < nums.size() / 2;i++) {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + nums.size() / 2]);
        }
        return ans;
    }
};