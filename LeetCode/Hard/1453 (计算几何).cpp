/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-17 23:04:25
 */ 
class Solution {
public:
    // 计算在一个指定圆里，最多可以有多少个点?
    // 先定其中两个点，然后暴力所有的点， 复杂度是 n^3, 可以做到 n^2 logn
    int numPoints(vector<vector<int>>& points, int r) {
        int n = points.size();
        if(n <= 1) {
            return n;
        }
        int ans = 1;
        typedef complex<double> Point;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    // 画个图，以下逻辑就容易懂了
                    Point p1(points[i][0], points[i][1]);
                    Point p2(points[j][0], points[j][1]);
                    double d = abs(p2 - p1) / 2.0;
                    if (d > r) continue;
                    Point p3 = (p1 + p2) / 2.0;
                    double h = sqrt(r * r - d * d);
                    Point dir = p2 - p3;
                    Point c1 = p3 + dir * Point{0, h / d};
                    ans = max(ans, PointInCircle(points, c1, r, i, j));
                    Point c2 = p3 - dir * Point{0, h / d};
                    ans = max(ans, PointInCircle(points, c2, r, i, j));
                }
            }
        }
        return ans;
    }
    int PointInCircle(vector<vector<int>>& points, complex<double>& mid, int r, int i, int j) {
        int n = points.size();
        int cnt = 2;
        double eps = 1e-9;
        for(int k = 0; k < n; k++) {
            if(i != k && j != k) {
                if(abs(complex<double>(points[k][0], points[k][1]) - mid) < r + eps) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};