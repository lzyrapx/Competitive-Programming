/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-17 01:02:20
 */
class Solution {
public:
    void dfs(vector<vector<int>>&ans, vector<int>&tmp, vector<int>&vis, int id, int n, int k) {
        if(tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        for(int i = id; i <= n; i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                tmp.push_back(i);
                dfs(ans, tmp, vis, i,  n, k);
                vis[i] = 0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>tmp;
        vector<int>vis(n + 1, 0);
        dfs(ans, tmp, vis, 1, n, k);
        return ans;
    }
};