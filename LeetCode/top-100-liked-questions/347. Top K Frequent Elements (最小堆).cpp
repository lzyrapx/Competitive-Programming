class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        if(nums.size() == 0) return ans;
        priority_queue<int,vector<int>, greater<int>> max_k; // 从大到小
        map<int,int>mp;
        for(auto i : nums) {
            mp[i]++;
        }
        for(auto &i : mp)
        {
            max_k.push(i.second);
            // 维护最小堆
            while(max_k.size() > k) {
                max_k.pop();
            }
        }
        for(auto &i: mp)
        {
            if(i.second >= max_k.top()) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};