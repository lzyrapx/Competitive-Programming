#include  <bits/stdc++.h>
using namespace std;

// https://www.lydsy.com/JudgeOnline/problem.php?id=1467
// http://poj.org/problem?id=3243
// 给定a,b,p，计算满足 a^x ≡ b ( mod p)的最小非负整数x, p为任意整数
// 复杂度：O(sqrt(p))

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
map<ll,ll>mp;
void EXBSGS(ll a, ll b,ll p)
{
  a %= p;
  b %= p;
  if(b == 1) {
    std::cout << "0" << '\n';return;
  }
  ll t = 0,d = 1,k = 0;
  while((t = __gcd(a,p)) != 1)
  {
      if(b % t) {
        std::cout << "No Solution" << '\n';
        return;
      }
      ++k,b /= t,p /= t, d = d * (a / t ) % p;
      if(b == d){
        std::cout << k << '\n';
        return;
      }
  }
  mp.clear();
  ll m = ceil(sqrt(p));
  ll a_m = qpower(a,m,p);
  ll mul = b;
  for(ll j = 1;j <= m; j++)
  {
      mul = mul * a % p;
      mp[mul] = j;
  }
  for(ll i = 1;i <= m; i++)
  {
      d = d * a_m % p;
      if(mp[d]) {
        std::cout << i * m - mp[d] + k << '\n';
        return;
      }
  }
  std::cout << "No Solution" << '\n';
}
int main(int argc, char const *argv[]) {
  // freopen("in.txt","r",stdin);
  ll a,b,p;
  while(std::cin >> a >> p >> b) {
    if(a == 0 && b == 0 && p == 0)break;
    EXBSGS(a,b,p);
  }
  return 0;
}
