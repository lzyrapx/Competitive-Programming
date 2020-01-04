/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-01 21:33:18
 */
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans = "";
        int cnt = 0;
        for(int i = S.size() - 1; i >= 0; --i) {
            if(S[i] == '-') continue;
            cnt++;
            ans += string(1, toupper(S[i]));
            if(cnt == K) {
                ans += "-";
                cnt = 0;
            }
        }
        if (ans[ans.size()-1] == '-') ans.erase(ans.size()-1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};