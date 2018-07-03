#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[10];
ll calc(ll limit,ll l,ll r)
{
	ll res = 0;
	ll last = 0;
	for(ll i = l;i<=min(limit,r);i=last+1)
	{
		last = min(limit/(limit/i),r);
		res += limit/i*(last-i+1);
	}
	return res;
}
int main()
{
	int l,r;
	scanf("%d%d",&l,&r);
	for(int i=1;i<=9;i++)
	{
		ll x = i;
		for(;x<=r;x*=10)
		{
			ll L = x;
			ll R = x/i*(i+1)-1;
			ans[i] += calc(r,L,R)-calc(l-1,L,R);
		}
		printf("%lld\n",ans[i]);
	}
	return 0;
}