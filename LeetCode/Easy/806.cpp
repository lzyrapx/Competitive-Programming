/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-18 00:00:30
 */
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int>ans(2, 0);
        if(widths.size() == 0 || S.size() == 0) return ans;
        ans[0] = 1;
        for(int i = 0; i < S.size(); i++) {
            if(ans[1] + widths[S[i] - 'a'] <= 100) {
                ans[1] += widths[S[i] - 'a'];
            }
            else {
                ans[1] = widths[S[i] - 'a'];
                ans[0] += 1;
            }
        }
        return ans;
    }
};