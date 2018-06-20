class Solution {
public:
    // 贪心+构造
    string reorganizeString(string S) {
        map<char,int>mp;
        int cnt = 0;
        for(char c : S)
        {
            mp[c]++;
            cnt = max(mp[c],cnt);
        }
        if(cnt > (S.size() + 1) / 2) return "";
        priority_queue< pair<int,char> >pq;
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        int idx = 0;
        while(!pq.empty())
        {
            pair<int,int> cur = pq.top();
            pq.pop();
            while(cur.first > 0)
            {
                cur.first--;
                S[idx] = cur.second;
                idx += 2;
                if(idx >= S.size()) {
                    idx = 1;
                }
            }
        }
        return S;
    }
};