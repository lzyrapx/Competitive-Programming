/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-29 01:23:49
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-29 01:23:49
 */
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        map<int, set<int>>tmp;
        
        map<int,int>groupIndeg;
        map<int,set<int>>groupMap;
        
        map<int,int>itemIndeg;
        map<int,set<int>>itemMap;
        
        int cnt = m;
        for(int i = 0; i < group.size(); i++) {
            if(group[i] == -1) {
                group[i] = cnt++;
            }
            tmp[group[i]].insert(i);
        }
        for(int to = 0; to < beforeItems.size(); to++) {
            int toGroup = group[to];
            for(auto from: beforeItems[to]) {
                int fromGroup = group[from];
                if(toGroup == fromGroup){ // 组内
                    itemMap[from].insert(to);
                    itemIndeg[to]++;
                } else {
                    if(groupMap[fromGroup].count(toGroup) == 0) { // 小组间
                        groupMap[fromGroup].insert(toGroup);
                        groupIndeg[toGroup]++;
                    }
                }
            }
        }
        // 小组间不能有环
        queue<int>que;
        vector<int>groupAns;
        for(int to = 0; to < cnt; to++) {
            if(groupIndeg[to] == 0) {
                que.push(to);
                groupAns.push_back(to);
            }
        }
        while(!que.empty()) {
            int from = que.front();
            que.pop();
            for(int to: groupMap[from]) {
                groupIndeg[to]--;
                if(groupIndeg[to] == 0) {
                    que.push(to);
                    groupAns.push_back(to);
                }
            }
        }
        if(groupAns.size() != cnt) return {};
        // 组内item 不能有环
        vector<int>ans;
        for(auto id: groupAns) {
            auto items = tmp[id];
            int num = 0;
            for(auto to: items) {
                if(itemIndeg[to] == 0) {
                    que.push(to);
                    ans.push_back(to);
                    num++;
                }
            }
            while(!que.empty()) {
                int from = que.front();
                que.pop();
                for(auto to: itemMap[from]) {
                    itemIndeg[to] --;
                    if(itemIndeg[to] == 0) {
                        que.push(to);
                        ans.push_back(to);
                        num++;
                    }
                }
            }
            if(num != items.size()) return {};
        }    
        return ans;
    }
};