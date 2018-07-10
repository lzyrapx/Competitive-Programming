class Solution {
public:
    //给一堆天气温度 ,找到之后的第几天第一次比这天温度高,没找到填0
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        if(temperatures.size() == 1) return ans;
        stack<int>sta;
        int n = temperatures.size();
        ans.resize(n);
        for(int i = 0; i < n; i++) {
            while(!sta.empty() && temperatures[sta.top()] < temperatures[i]) {
                ans[sta.top()] = i - sta.top();
                sta.pop();
            }
            sta.push(i);
        }
        return ans;
    }
};