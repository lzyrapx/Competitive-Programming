class Solution {
public:
    // buildings[i][0]是 起始点, buildings[i][1]是 结束点, buildings[i][2]是 高(H)
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int> > ans;
        if(buildings.size() == 0) return ans;

        int cur_x = 0, cur_h = -1;
        int n = buildings.size();
        priority_queue< pair<int, int>> pq; // pair(height, X)
        
        int i = 0;
        while(i < n || !pq.empty())
        {
           if(pq.empty()) {
               cur_x = buildings[i][0]; // 当前最高建筑的结束点
           }
            else {
                cur_x = pq.top().second; // 当前最高建筑的结束点
            }
            // 如果当前最高建筑的结束点 在 下一个建筑物的结束点的前面
            if(i >= n || cur_x  < buildings[i][0]) {
                // 那么，将结束点 在 当前最高建筑结束点 前面的 那些建筑物从优先队列中弹出
                while(!pq.empty() && pq.top().second <= cur_x) pq.pop();
            }
            // 如果下一个建筑的结束点 在 当前最高建筑物的结束点的前面
            else if(buildings[i][0] <= cur_x)
            {
                cur_x = buildings[i][0];
                while(i < n && buildings[i][0] == cur_x) // 处理所有在同一点开始的建筑物
                {  
                    pq.push(make_pair(buildings[i][2],buildings[i][1]));
                    i++;
                }
            }
            cur_h = pq.empty() ? 0 : pq.top().first; // 输出最顶端的建筑物的高度
            if(ans.empty() || ans.back().second != cur_h)  {
                ans.push_back(make_pair(cur_x, cur_h));
            }
        }
        return ans;
    }
};