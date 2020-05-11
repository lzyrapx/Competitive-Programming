/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-11 23:30:57
 */
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0];
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        }
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge:edges) {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1]; // u -> v
            int pa = root(parent, u);
            // Now every node only has 1 parent, so root of v is implicitly v
            if (pa == v) {
                if (candA.empty()) return edge;
                else return candA;
            }
            else {
                parent[v] = pa;
            }
        }
        return candB;
    }
    int root(vector<int>& parent, int k) {
        if (parent[k] != k) parent[k] = root(parent, parent[k]);
        return parent[k];
    }
};