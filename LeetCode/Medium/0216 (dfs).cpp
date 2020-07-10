/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-10 23:44:38
 */ 
class Solution {
public:
    vector<vector<int>>ans;
    vector<int>subset;
    void dfs(int &k, int target, int start) {
        if(target < 0 || subset.size() > k) {
            return;
        }
        if(subset.size() == k && target == 0) {
            ans.push_back(subset);
        }
        for(int i = start; i <= 9; i++) {
            subset.push_back(i);
            dfs(k, target - i, i + 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k == 0) {
            return {};
        }
        dfs(k, n , 1);
        return ans;
    }
};