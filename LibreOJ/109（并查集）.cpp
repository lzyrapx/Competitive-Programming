#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m;
int fa[8000010];

int ans = 0;
int  getfather(int x)
{
	return fa[x]==x?x:fa[x]=getfather(fa[x]);
}

int main()
{
	int op,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&op,&u,&v);
		if(op==0)
		{
			int a=getfather(u);
			int b=getfather(v);
			if(a!=b)
			{
				fa[a]=b;
			}
		}
		else if(op==1)
		{
			int a=getfather(u);
			int b=getfather(v);
			if(a==b)
			{
				ans = (ans*2 + 1)%mod;	
			}
			else
			{
				ans=ans*2;
			}
		}
	}
	printf("%d\n",ans);
}