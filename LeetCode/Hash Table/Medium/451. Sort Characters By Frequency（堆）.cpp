class Solution {
public:
    struct cmp
    {
      bool operator()(const pair<int,char>&a, pair<int,char>&b) {
         if(a.first == b.first) return a.second < b.second;
          return a.first < b.first;
      }
    };
    string frequencySort(string s) {
        string ans = "";
       if(s.size() == 0) return ans;
        
        unordered_map<char,int>mp;
        for(auto ch : s) {
            mp[ch]++;
        }
        priority_queue< pair<int,char>,vector<pair<int,char>>,cmp >pq;
        
        for(auto x : mp)
        {
            pq.push({x.second,x.first});
        }
        while(!pq.empty())
        { 
            auto cur = pq.top();
            pq.pop();
            int num = cur.first;
            for(int i = 1; i <= num; i++){
                ans += cur.second; // ans = ans + cur.second 最后一组数据会MLE, +=会节省内存...
            }
        }
        return ans;
    }
};