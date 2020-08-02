/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-08-02 14:14:19
 */ 
class Solution {
public:
    // 从图中找最小高度树
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if(n == 1) {
            ans.push_back(0);
            return ans;
        }
        vector<vector<int>>tree(n);
        vector<int>degree;
        queue<int>que;
        for(int i = 0; i < n; i++) {
            degree.push_back(0);
        }
        for(auto e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) {
                que.push(i);
            }
        }
        int res = n;
        // 逐层去除某些节点
        while(res != 1 && res != 2) {
            int sz = que.size();
            res -= sz;
            for(int i = 0; i < sz; i++) {
                int cur = que.front();
                que.pop();
                for(auto v: tree[cur]) {
                    if(degree[v] > 0) {
                        degree[v]--;
                    }
                    if(degree[v] == 1) {
                        que.push(v);
                    }
                }
            }
        }
        while(!que.empty()) {
            ans.push_back(que.front());
            que.pop();
        }
        return ans;
    }
};