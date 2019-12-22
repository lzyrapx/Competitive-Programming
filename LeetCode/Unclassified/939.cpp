/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-20 01:09:48
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-20 01:09:48
 */
class Solution {
public:
    // 1 <= points.length <= 500
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>>se;
        const int sz = points.size();
        for(auto p : points) {
            se.insert({p[0], p[1]});
        }
        int res = 1e9;
        for(int i = 1; i < sz; i++) {
            for(int j = 0; j < i; j++) {
                if(i == j) continue;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2 ||  y1 == y2) continue;
                if(se.count({x1, y2}) && se.count({x2, y1})) {
                    res = min(res, abs((x1 - x2) * (y1 - y2)));
                }
            }
        }
        if(res == 1e9) {
            return 0;
        }
        else return res;
    }
};