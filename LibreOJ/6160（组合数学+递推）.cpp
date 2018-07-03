#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10000010;
const int mod = 1e9+7;
ll fac[maxn],inv[maxn];
//http://blog.csdn.net/u014609452/article/details/73744264
ll C(int n,int m)
{
	return fac[n] * inv[m] % mod *inv[n-m]%mod; 
}
ll A(int n,int m)
{
	return fac[n] * inv[n-m] %mod;
}
int n;
ll b[maxn];
int main()
{	
	scanf("%d",&n);
	b[0] = 1;
	b[1] = 2;
	for(int i=2;i<=n;i++)
	{
		b[i]=(1LL * 2 * i * b[i-1] % mod + mod - 1LL*(i-1) * (i-1) % mod * b[i-2] % mod)%mod;
	}
	
	ll ans = 0;
	fac[0]=1;
	for (int i=1;i<=n;i++)
	{
		fac[i] = fac[i-1] * i % mod;
	}
  	inv[1]=1; 
	for (int i=2;i<=n;i++) 
	{ 
		inv[i]=1LL*(mod-mod/i) * inv[mod % i]%mod;
	}
  	inv[0]=1; 
	for (int i=1;i<=n;i++) 
	{
		inv[i]=inv[i-1]*inv[i]%mod;	
	}
	
	for(int i=0;i<=n;i++)
	{
		if(i&1){
			ans +=  mod - C(n,i) * A(n,i) % mod * b[n-i] % mod * b[n-i] % mod;
		}
		else{
			ans += C(n,i) * A(n,i) %mod * b[n-i] %mod *b[n-i] % mod; 
		}
	}
	printf("%lld\n",ans%mod);
	return 0;	
} 