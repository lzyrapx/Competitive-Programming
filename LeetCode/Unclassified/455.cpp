/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-22 22:42:01
 */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = 0, j = 0; i < g.size() && j < s.size();) {
            if(s[j] >= g[i]) {
                cnt++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return cnt;
    }
};