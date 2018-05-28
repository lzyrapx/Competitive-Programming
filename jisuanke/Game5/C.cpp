#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxn = 1e6 + 11;
int f[maxn];
ll N,K;
map<int,ll> mp;
map<int,ll> cnt;
void init() 
{
    for (int i = 1; i < maxn; i++) {
        int t = i, res = 1;
        while (t > 0) res *= t % 10, t /= 10;
        if (i % 10 == 0) res = 0;
        f[i] = res;
    }
}
int main()
{
    init();
    cin >> N >> K;
    K = min(K, 1000000LL);
    for (int i = 1; i <= N; i++) {
      if (f[i])  {
        mp[f[i]]++;
      }
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        for (auto j = mp.begin(); j != mp.end(); j++)
        {
            int gcd = __gcd(i->first,j->first);
            if (gcd <= K)
            {
                cnt[gcd] += i->second * j->second;
                cnt[gcd] %= mod;
            }
        }
    }
    ll ans = 0;
    for (auto x : cnt) {
      ans = (ans + x.second) % mod;
    }
    cout << ans << endl;
    return 0;
}
