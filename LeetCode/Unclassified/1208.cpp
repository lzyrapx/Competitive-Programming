/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-02 16:43:37
 */
class Solution {
public:
    // 1 <= s.length == t.length <= 1e5
    // 0 <= maxCost <= 1e6
    // sliding window 
    // 滑动窗口
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int curCost = 0;
        vector<int>ve;
        for(int i = 0; i < s.size(); i++) {
            ve.push_back(abs(s[i] - t[i]));
        }
        for(int i = 0; i < ve.size(); i++) {
            curCost += ve[i];
            while(curCost > maxCost && left < s.size()) {
                curCost -= ve[left];
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};