#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll now;
ll n;
ll ans=-9999999999;
ll x;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(now<0){
			now=0;
		}
		cin>>x;
		now+=x;
		if(now>ans)
		{
			ans=now;
		}
	}
	cout<<ans<<endl;
	return 0;
}