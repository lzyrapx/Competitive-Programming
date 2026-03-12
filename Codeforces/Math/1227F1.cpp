/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-02 23:32:28
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
typedef long long ll;
 
const int mod = 998244353;
const int maxn = 2e5 + 123;
int n, k;

ll qpower(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
ll fac[maxn], inv[maxn];

ll C(int n,int m){
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
void init() {
    fac[0] = inv[0] = 1;
    for(int i = 1; i < maxn; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = qpower(i, mod - 2) * inv[i - 1] % mod;
    }
}
int main()
{
    init();
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    if(k == 1) {
        cout << 0 << endl;
        return 0;
    }
    int num = 0;

    for(int i = 0; i < n; i++) {
        if(h[i] != h[(i + 1) % n]) {
            num++;
        }
    }
    ll ans = 0;
    for(int i = 0; 2 * i <= num; i++) {
        ll cur = C(num, i) * C(num - i, i) % mod * qpower(k - 2, num - 2 * i) % mod * qpower(k, n - num) % mod;
        ans = (ans + cur) % mod;
    }
    ll total = qpower(k , n);
    cout << (total - ans + mod) * inv[2] % mod << endl;
    return 0;
}