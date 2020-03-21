/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-21 16:50:07
 */
class Solution {
public:
    // 1 <= words.length <= 1000
    int longestStrChain(vector<string>& words) {
        if(words.size() == 1) {
            return 1;
        }
        sort(words.begin(), words.end(), [&](string s1, string s2) -> bool {
          return s1.size() < s2.size();  
        });
        unordered_map<string,int>dp;
        int ans = 0;
        for(auto s: words) {
            for(int i = 0; i < s.size(); i++) {
                dp[s] = max(dp[s], dp[s.substr(0, i) + s.substr(i + 1)] + 1);
            }
            ans = max(ans, dp[s]);
        }
        return ans;
    }
};