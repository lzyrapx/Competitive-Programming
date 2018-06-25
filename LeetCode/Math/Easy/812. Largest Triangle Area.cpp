class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for(auto a : points) {
            for(auto b : points) {
                for(auto c : points) {
                    ans = max(ans,0.5 * abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - b[0] * a[1] - c[0] * b[1] - a[0] * c[1]));
                }
            }
        }
        return ans;
    }
};