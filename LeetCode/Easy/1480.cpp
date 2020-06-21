/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-21 18:30:20
 */ 
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>presum;
        presum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            presum.push_back(presum.back() + nums[i]);
        }
        return presum;
    }
};