#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 1000;
const int mod = 998244353;

int inv[maxn];
ll qpower(ll a, ll b,ll mod)
{
    long long ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int t;
    inv[0] = 1;
    for(int i = 0; i <= 1000; i++){
        inv[i] = qpower(i, mod - 2, mod);
    }
    // cout << inv[100] << endl;
    cin >> t;
    while(t--) {
        int m, q, p;
        int ans = 0;
        cin >> m >> p >> q;
        ll tmp = 100ll * inv[p] % mod * m % mod + mod - 1;
        ans = (m + mod - tmp * q % mod * inv[100] % mod) % mod;
        cout << ans << endl;
    }
    return 0;
}
