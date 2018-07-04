class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>path;
        vector<vector<int>> ans;
        int begin = 0;
        dfs(nums, target, path, ans, begin);
        return ans;
    }
    void dfs(vector<int>&nums, int target, vector<int>&path, vector<vector<int> >& ans, int begin)
    {
        if(target <= 0) {
            if(target == 0) {
                ans.push_back(path);
            }
            return;
        }
        int n = nums.size();
        for(int i = begin; i < n; i++) {
            path.push_back(nums[i]);
            dfs(nums, target - nums[i], path, ans, i);
            path.pop_back();
        }
    }
};