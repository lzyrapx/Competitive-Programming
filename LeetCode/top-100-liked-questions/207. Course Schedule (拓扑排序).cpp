class Solution {
public:
    // 拓扑排序： O(m + n)
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        vector<int>indegree(numCourses + 1, 0);
        vector<vector<int>> g(numCourses);
        for(auto e: prerequisites) {
            g[e.second].push_back(e.first);
            indegree[e.first]++;
        }
        queue<int>que;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            
            for(auto nxt: g[cur])
            {
                indegree[nxt]--;
                if(indegree[nxt] == 0) {
                    que.push(nxt);
                }
            }
            g[cur].clear();
        }
        
        for(auto cur : g)
        {
            if(!cur.empty()) {
                return false; // 有个环
            }
        }
        return true;
    }
};