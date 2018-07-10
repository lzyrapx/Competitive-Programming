class Solution {
public:
    struct cmp
    {
        bool operator() (const pair<int,string>&a, const pair<int,string>&b) { // first是出现次数, second是字符串
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        if(words.size() == 0) return ans;
        if(words.size() < k) return words;
        map<string,int>mp;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            mp[words[i]]++;
        }
        // 出现次数最小到大,出现次数相等就字典序从大到小，维护一个堆
        priority_queue< pair<int,string>, vector< pair<int,string> >, cmp> max_k;
        for(auto x : mp) {
            max_k.push({x.second, x.first});
        }
        for(int i = 0; i < k; i++) {
            ans.push_back(max_k.top().second);
            max_k.pop();
        }
        return ans;
    }
};