#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void extend_Euclid(ll a, ll b, ll *x, ll *y, ll *g)
{
	if(a == 0)
	{
		*x = 0, *y = 1 , *g = b;
		return;
	}
	ll x1,y1;
	extend_Euclid(b%a, a, &x1, &y1, g);
	*x = y1 - (b/a)*x1;
	*y = x1;
}

ll crt(ll* a, ll* w, int len)//a存放的是余数，w存放的是两两互质的模数 
{
	ll P = 1; 
	for(int i=0; i<len; i++) P*=w[i];
	ll x = 0;
	for(int i=0; i<len; i++)
	{
		ll M, m, g, Ni = P/w[i];
		extend_Euclid(Ni , w[i], &M, &m, &g);
		x += a[i] * M % P * Ni % P;
		x %= P;
	}
	if(x < 0) x+=P;
	return x % P;
}

ll a[123];//余数 
ll w[132];//两两互质的模数 
int main()
{	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&w[i],&a[i]);
	}
	ll ans=crt(a,w,n);
	cout<<ans<<endl;
    return 0;
}
