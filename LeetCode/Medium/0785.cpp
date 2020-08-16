class Solution {
public:
    //  判断是否是二分图?
    bool dfs(vector<vector<int>>& graph, int i, int color, vector<int>&vis) {
        if(vis[i] != -1) {
            if(vis[i] == color) {
                return true;
            }
            return false;
        }
        vis[i] = color;
        for(int j: graph[i]) {
            if(dfs(graph, j, !color, vis) == false) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<int>vis(sz, -1);
        for(int i = 0; i < sz; i++) {
            if(vis[i] == -1 && dfs(graph, i, 0, vis) == false) {
                return false;
            }
        }
        return true;
    }
};