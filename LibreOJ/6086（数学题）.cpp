#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =5000010;
const int mod = 1000000007;
int n,m,num;
ll l[maxn],j[maxn],k[maxn];
ll x[maxn],y[maxn],z[maxn];
int main()
{
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&l[i],&j[i],&k[i]);
		x[i] = l[i] - j[i];
		y[i] = j[i] - k[i];
		z[i] = k[i] - l[i];
	}
	ll ans = 0;
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	sort(z+1,z+n+1);
	for(int i=1;i<=n;i++)
	{
		 ans = (ans + 1LL*(2*i-n-1)*(x[i]+y[i]+z[i])) % mod;
	}
	printf("%lld\n",(ans*500000004)%mod);
	return 0;
 } 