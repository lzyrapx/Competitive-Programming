/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-28 23:32:04
 */
class Solution {
public:
    bool dfs(int a, int b, int c, int d, vector<int>&x, int cur) { 
        if(a >= c && d >= b) {
            return true;
        }
        if(cur == x.size() - 1) {
            return false;
        }
        if(cur + 1 < x.size() && b == d && c - a <= x[cur + 1]) {
            return true;
        }
        if(cur + 2 < x.size() && d >= b && c >= x[cur + 1] && c - a <= x[cur + 1] && d - b <= x[cur + 2]) {
            return true;
        }
        return dfs(b, c, d, x[cur + 1], x, cur + 1);
    }
    bool isSelfCrossing(vector<int>& x) {
        if(x.size() < 4) {
            return false;
        }
        return dfs(x[0],x[1],x[2],x[3],x,3);
    }
};