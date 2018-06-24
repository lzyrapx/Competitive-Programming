class Solution {
public:
    // 注意边界：要long long...
    int reverse(int x) {
        if(x < 0) {
            x = -x;
            long long ans = 0;
            while(x){
                ans *= 10;
                ans += x %10;
                x /= 10;
            }
            ans = -ans;
            if(INT_MIN > ans || INT_MAX < ans) return 0;
            return ans;
        }
        else
        {
            long long  ans = 0;
            while(x)
            {
                ans*=10;
                ans += x % 10;
                x /= 10;
            }
            if(INT_MIN > ans || INT_MAX < ans) return 0;
            return ans;
        }
    }
};
