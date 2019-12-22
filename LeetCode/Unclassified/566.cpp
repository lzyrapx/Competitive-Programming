/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-27 22:42:17
 */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        int sz = m * n;
        if(r * c != sz) return nums;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for(int i = 0; i < sz; i++) {
            ans[i / c][i % c] = nums[i / n][i % n]; 
        }
        return ans;
    }
};