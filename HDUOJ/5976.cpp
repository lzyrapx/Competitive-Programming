#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100000000
const ll maxn = 1000000;
const ll mod = 1e9 + 7;
ll num[maxn];
void init() //阶乘
{
	ll temp = 1;
	num[0] = 1;
	for (ll i = 1; i < maxn; i++)
	{
		temp = (temp*i) % mod;
		num[i]=temp;
	}
}

ll gao(ll k)
{
	if (k == 1) return 1;
	return (( -(mod / k) * gao(mod % k) ) % mod + mod) % mod;
}
int main()
{
	ll t;
	ll n, x, y;
	ll ans;
	
	init();
	
	scanf("%lld", &t);
	while (t--) 
	{
		scanf("%lld" , &n);
		if(n==1)
		{
			puts("1");
			continue;
		}
		x = ((ll)sqrt(2 * n));
		while ( x * (x + 1) >> 1 < n ) ++x;
		
		y = (x * (x + 1) >> 1) - n;
		switch (y)
		{
			case 0 :
			ans= num[x + 1] * gao(x);break;
			case 1 :
			ans= num[x]; break;
			case 2 :
			ans = num[x + 1] * gao(2 * x);break;
			default :
			ans = num[x] * gao(y - 1); break;
		}
 		ans %= mod;
		printf("%lld\n", ans);
	}
	return 0;
}
