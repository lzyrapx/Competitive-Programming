#include  <bits/stdc++.h>
using namespace std;

// https://www.lydsy.com/JudgeOnline/problem.php?id=2242
/*
1、给定y,z,p,计算 y^z Mod P 的值；

2、给定y,z,p，计算满足 xy≡ Z ( mod P )的最小非负整数；
yx + pY = gcd(y,p),如果 z 不是gcd的倍数则无解否则为 x/gcd*z

3、给定y,z,p，计算满足 y^x ≡ Z ( mod P)的最小非负整数。
*/
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
//一定存在整数x,y，使得ax+by=gcd(a,b)
ll exgcd(ll a,ll b,ll &x,ll &y)// 返回a,b的最大公约数
{
    if(!a && !b)return -1;
    if(!b)return x=1,y=0,a;
    ll d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}
void solve(ll y, ll z, ll p)
{
  if(y % p == 0) {
    std::cout << "Orz, I cannot find x!" << '\n';
    return;
  }
  ll X,Y;
  ll g = exgcd(y,p,X,Y);
  if(z % g != 0) {
    std::cout << "Orz, I cannot find x!" << '\n';
    return;
  }
  else {
    ll ans = ((X / g * z) % p + p) % p;
    std::cout << ans << '\n';
  }
}
map<ll,ll>mp;
void BSGS(ll y, ll z,ll p)
{
  if(y == 0 && z == 0) {
    std::cout << "1" << '\n';
    return;
  }
  if(y == 0 && z != 0) {
    std::cout << "Orz, I cannot find x!" << '\n';
    return;
  }
  mp.clear();
  ll tmp = 1;
  ll power = qpower(y, p - 2, p);
  ll k = ceil((sqrt(p)));
  mp[z] = k + 1;
  for(int i = 1; i < k; i++) {
    tmp = tmp * power % p;
    ll t = tmp * z % p;
    if(!mp[t]) mp[t] = i;
  }
  tmp = 1;
  power = qpower(y,k,p);
  for(int i = 0; i < k; i++, tmp = tmp * power % p)
  {
    if(mp[tmp])
    {
      if(mp[tmp] == k + 1) std::cout << i * k << '\n';
      else std::cout << i * k + mp[tmp] << '\n';
      return;
    }
  }
  std::cout << "Orz, I cannot find x!" << '\n';
}
int main(int argc, char const *argv[]) {
  // freopen("in.txt","r",stdin);
  int t,k;
  std::cin >> t >> k;
  while (t--) {
    ll y,z,p;
    std::cin >> y >> z >> p;
    y %= p; // 不加就 WA...
    if(k == 1) {
      std::cout << qpower(y,z,p) << '\n';
    }
    else if(k == 2) {
       z %= p;
       solve(y, z, p);
    }
    else {
      z %= p;
      BSGS(y,z,p);
    }
  }
  return 0;
}
