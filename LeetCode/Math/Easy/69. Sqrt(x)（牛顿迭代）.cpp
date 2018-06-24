class Solution {
public:
    int mySqrt(int x) {
        double ans = x;
        double eps = 0.0001;
        while(fabs(pow(ans,2) - x) > eps) {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};