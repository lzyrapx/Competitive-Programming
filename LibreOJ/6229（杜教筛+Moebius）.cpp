#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6+100;
const int mod = 1e9+7;
int n;
int p[maxn],phi[maxn],pre[maxn];

int inv2,inv6;
ll qpower(ll a,ll b,ll mod)
{
  ll res = 1;
  while(b>0) {
    if(b&1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
void init(int n)
{
  phi[1]=1;
  for(int i=2;i<=n;i++)
  {
    if(p[i]==0) p[++*p]=i,phi[i]=i-1;
    for(int j=1;j<=*p && 1LL*p[j]*i<=n;j++)
    {
      p[p[j]*i]=1;
      if(i%p[j]) phi[i*p[j]]=phi[i]*phi[p[j]];
      else
      {
        phi[i*p[j]]=phi[i]*p[j];
        break;
      }
    }
  }
  for(int i=1;i<=n;i++) {
    pre[i]=(pre[i-1]+1LL*phi[i]*i%mod*i)%mod;
  }
}
map<ll,int> mp;
int calcinv2(ll l,ll r)
{
  l %= mod;
  r %= mod;
  return (r - l + 1) * (l + r) % mod * inv2 % mod;
}
int calcinv6(ll n)
{
  n %= mod;
  return n * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod;
}
int calc2(ll l,ll r)
{
 return (calcinv6(r) - calcinv6(l-1) ) % mod;
}
int calc3(ll n)
{
  return 1LL * calcinv2(1 , n) * calcinv2(1 , n) % mod;
}
int S(ll n)
{
  if(n <= 1e6) return pre[n];
  if(mp.count(n)) return mp[n];
  int res = calc3(n);
  for(ll i = 2, j; i <= n ;i = j + 1) {
    j = n / (n / i);
    res = (res - 1LL * calc2(i,j) * S(n / i)) % mod;
  }
  return mp[n] = res;
}
int main(int argc, char const *argv[]) {

  ll n;
  std::cin >> n;
  init(1000000);// 2/3
  inv2 = qpower(2,mod-2,mod);
  inv6 = qpower(6,mod-2,mod);
  int ans = 0;
  int last = 0;
  for(ll i = 1, j; i <= n; i = j + 1) {
    j = n /( n / i );
    int cur = S(j);
    ans = (ans + 1LL * (cur - last) * ( n / i)) % mod;
    last  = cur;
  }
  ans = (ans + n) % mod * inv2 % mod;
  std::cout << (ans + mod) % mod << '\n';
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
