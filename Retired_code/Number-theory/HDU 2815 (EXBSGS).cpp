#include  <bits/stdc++.h>
using namespace std;

// http://acm.hdu.edu.cn/showproblem.php?pid=2815
// 给定y,z,p，计算满足 y^x ≡ z ( mod p)的最小非负整数x., p为任意整数
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
        std::cout << "Orz,I can’t find D!" << '\n';
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
  std::cout << "Orz,I can’t find D!" << '\n';
}
int main(int argc, char const *argv[]) {
  // freopen("in.txt","r",stdin);
  ll n,k,p;
  while(std::cin >> k >> p >> n) {
    if(n >= p) {
      std::cout << "Orz,I can’t find D!" << '\n';
      continue;
    }
    // if(a == 0 && b == 0 && p == 0)break;
    EXBSGS(k,n,p);
  }
  return 0;
}
