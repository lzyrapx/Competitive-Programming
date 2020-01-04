/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-22 12:56:35
 */
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size() - 1; i++) {
            int diffx = abs(points[i][0] - points[i + 1][0]);
            int diffy = abs(points[i][1] - points[i + 1][1]);
            ans += max(diffx, diffy);
        }
        return ans;
    }
};