class Solution {
public:
    // 类似欧拉路径
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> graph;
        for(auto t: tickets) {
            graph[t[0]].push(t[1]);
        }
        vector<string>ans;
        stack<string>route;
        route.push("JFK");
        while(!route.empty()) {
            string city = route.top();
            if(graph[city].empty()) {
                ans.push_back(city);
                route.pop();
            }
            else {
                route.push(graph[city].top());
                graph[city].pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};