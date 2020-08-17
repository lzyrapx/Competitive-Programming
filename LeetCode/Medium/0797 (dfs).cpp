class Solution {
public:
    // 给你 N 个点的有向图，输出所有从 0 - N-1 的路径
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        vector<vector<int>>ans;
        dfs(ans, path, graph,0);
        return ans;
    }
    void dfs(vector<vector<int>>&ans, vector<int>&path, vector<vector<int>>&graph, int node) {
        path.push_back(node);
        if(node == graph.size() - 1) {
            ans.push_back(path);
        }
        for(auto e: graph[node]) {
            dfs(ans, path, graph, e);
        }
        path.pop_back();
    }
};