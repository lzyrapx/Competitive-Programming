/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 18:18:29
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 18:18:29
 */
class Solution {
public:
    // -10000 <= x, y <= 10000
    int hypotenuseDis(vector<int>&p1, vector<int>&p2) {
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];
        return x * x + y * y;
    }
    bool triangle(vector<int>&p1, vector<int>&p2, vector<int>&p3) {
        vector<int> v = { hypotenuseDis(p1, p2), hypotenuseDis(p2, p3), hypotenuseDis(p1, p3)};
        sort(v.begin(), v.end());
        return v[0] > 0 && v[0] == v[1] && v[0] + v[1] == v[2];
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return triangle(p1,p2,p3) && triangle(p2, p3, p4) && triangle(p1, p2, p4) && triangle(p1, p3, p4);
        
    }
};