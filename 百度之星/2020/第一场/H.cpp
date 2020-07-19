#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const long long mod = 1e9 + 7;
const int maxn = 1234567;

typedef long long ll;
ll qpower(ll a, ll b,ll mod)
{
    long long ans=1;
    while(b>0) {
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int mu[maxn];
int f[maxn];
int prime[maxn];

ll get_value(ll n) {
    ll result = 0;
    ll t = 0;
    for(int i = 1; i <= sqrt(n); i++) {
        t = n / i;
        result = (result + n / i * i) % mod;
    }
    result = 2 * result % mod;
    // cout << "result = " << result << endl;
    ll k = 0;
    for(ll i = sqrt(n) + 1; i <= n; i = k + 1) {
        t = n / i;
        k = n / t;
        result = (result + t % mod * ((k - i + 1) % mod) % mod * ((i + k) % mod)) % mod;
    }
    return result * ((mod + 1) >> 1) % mod;
}
void init() {
    mu[1] = 1;
    int pcnt = 0;
    for(int i = 2; i < maxn; i++) {
         if (!f[i]) prime[++pcnt] = i, mu[i] = -1;
         for(int j = 1; j <= pcnt; j++) {
            int x = i * prime[j];
            if (x >= maxn) break;
            f[x] = 1;
            if (i % prime[j] == 0) break;
            mu[x] = -mu[i];
         }
    }
}
int main(int argc, char const *argv[])
{
    init();
    int t = 0;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        for(ll i = 1; i * i <= n; i++) {
            ans = (ans + (mu[i] * i + mod) * get_value(n / i / i)) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}