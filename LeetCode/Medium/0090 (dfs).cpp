/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-06 00:21:50
 */ 
class Solution {
public:
    void dfs(vector<vector<int>>&res, vector<int>&subset, vector<int>&nums, set<vector<int>>&se, int idx) {
        if(se.find(subset) == se.end()) {
            se.insert(subset);
            res.push_back(subset);
        }
        for(int i = idx; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            dfs(res, subset, nums, se, i + 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>subset;
        set<vector<int>>se;
        dfs(res, subset, nums, se, 0);
        return res;
    }
};