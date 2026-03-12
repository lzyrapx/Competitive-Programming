#include<bits/stdc++.h>
using namespace std;
int f[34],vis[34];
void init()
{
	f[1] = 1;f[2] = 2;
	for(int i=3;i<=30;i++){
		f[i] = f[i-1] + f[i-2];
	}
}
int main()
{
	int n,m;
	cin>>n;
	init();
	while(n--)
	{
		cin>>m;
		memset(vis,0,sizeof(vis));
		for(int i=29;i>=1;--i)
		{
			if(m<=0)break;
			if(f[i]<=m)
			{
				m-=f[i];
				vis[i] = 1;
			}
		}
		int ans = 0;
		for(int i=2;i<=29;i++){
			ans += vis[i]*f[i-1];
		}
		cout<<ans<<endl; 
	}
	return 0;
}