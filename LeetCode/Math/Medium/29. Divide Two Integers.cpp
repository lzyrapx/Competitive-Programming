class Solution {
public:
    // O((log N)^2)
    typedef long long ll;
    int divide(int n_, int d_) {
        ll ans = 0;
        ll n = abs(1LL*n_);
        ll d = abs(1LL*d_);
        while(n >= d)
        {
            ll a = d;
            ll m = 1;
            while((a << 1) < n)
            {
                a <<= 1;
                m <<= 1;
            }
            ans += m;
            n -= a;
        }
        ll res = 0;
        if((n_ < 0 && d_ >= 0) || (n_ >= 0 && d_ < 0)){
            res = -ans;
        } 
        else res = ans;
        
        
        // cout << "res = " << res <<endl;
        if(res > INT_MAX && res > 0) return INT_MAX;
        else if(res < INT_MIN && res < 0) return INT_MIN;
        return res;
    }
};
