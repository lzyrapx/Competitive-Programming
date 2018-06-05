class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        set<string>dict(words.begin(),words.end());
        for(auto x : words)
        {
            int sz = x.size();
            if(sz == 0) continue;
            // dp[i] 表示 words中的一个字符串 s[0,i] 是否存在在 dict中。
            vector<bool> dp(sz + 1, false);
            dp[0] = true;
            for(int i = 0; i < sz; i++)
            {
                if(dp[i] == 0) continue;
                for(int j = i + 1; j <= sz; j++)
                {
                    if(j - i  < sz && dict.count( x.substr(i, j - i)) == true)
                    {
                        dp[j] = true;
                    }
                }
                if(dp[sz] == true)
                {
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};