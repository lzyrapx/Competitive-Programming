class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        int f = 0;
        if(n < 0) f = 1;
        n = abs(n);
        while(n) {
            if(n % 2) ans = ans * x;
            n /= 2;
            x = x * x;
        }
        if(f == 1) ans = 1.0 / ans;
        return ans;
    }
};