/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-26 16:04:13
 */
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        pair<int,int>pii[56789];
        priority_queue<int>pq;
        int sum = W;
        for(int i = 0; i < Profits.size(); i++) {
            pii[i] = make_pair(Capital[i], Profits[i]);
        }
        sort(pii, pii + Profits.size());
        int cur = 0;
        for(int i = 0; i < k; i++) {
            while(cur < Profits.size() && pii[cur].first <= sum) {
                pq.push(pii[cur].second);
                cur++;
            }
            if(!pq.empty()) {
                int profit = pq.top();
                pq.pop();
                sum += profit;
            }
        }
        return sum;
    }
};