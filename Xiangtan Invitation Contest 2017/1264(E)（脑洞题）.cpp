#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m;
int c;
int a[maxn];

int main()
{
	while(~scanf("%d",&n))
	{
		a[0]=0;
		int b;
		cin>>m>>c;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b);
			a[i]=a[i-1]+b;
		}
		sort(a,a+n+1);
		ll ans = 0 ;
		for (int i=0;i<m;i++)
		{
			if(a[n-i]-a[i]<c)break;
			ans+=a[n-i]-a[i]-c;
		}
		cout<<ans<<endl;		
	}
	
	return 0;
}