class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int sz = envelopes.size();
        if(sz == 0) return 0;
        if(sz == 1) return 1;
        
        sort(envelopes.begin(),envelopes.end());
        
        vector<int> dp(sz + 1, 1);
        
        for(int i = 0; i < sz; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        int ans = 0;
        for(auto x : dp)
        {
            ans = max(ans,x);
        }
        return ans;
    }
};