#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 505000;
const int mod = 998244353;
ll n,k;

ll calc(ll x)
{
  ll ans = 1;
  while (x > 0) {
    ans *= (x % 10);
    x/=10;
  }
  return ans;
}
int main()
{
  ll ans = 0;
  std::cin >> n >> k;
  for(ll i = 1; i <= n;i++) {
    for(ll j = 1; j <= n;j++) {
      if(__gcd(calc(i),calc(j)) > 0 && __gcd(calc(i),calc(j)) <= k && (calc(i) * calc(j)) > 0){
        ans ++;
        ans %= mod;
      }
    }
  }
  std::cout << ans % mod<< '\n';
  return 0;
}
