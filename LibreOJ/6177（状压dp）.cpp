#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tot=1;
int n, m, q;
int s[15], t[15], l[15], r[15], dis[22][22];
int dp[60010][22];
/*
三进制状压DP。dp[i][j]表示三进制状态为 i，最终走到 j 点的最小时间花费。
那么状态对应一个位置是0表示没有取餐，是1表示取了餐没有送，2表示送到了，
然后分析每一位上是0还是1进行状态转移，转移之前要预处理一下最短路，
这个点比较少直接Floyd预处理一下即可
*/
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i] = 0;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		dis[u][v] = min(dis[u][v],w);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d%d%d",&s[i],&t[i],&l[i],&r[i]);//需要从点 s 送到 t ，在时间 l之后可以领取，时间 r 之前要送到 
		tot*=3;
	}
	memset(dp, 63, sizeof(dp));
	dp[0][1] = 0;
	for(int i=0;i<tot;i++)//可能的总状态数 
	{
		for(int j=1;j<=n;j++)  
		{
			if(dp[i][j]<=1e9)
			{
				for(int k=1;k<=n;k++)
				{
					if(dis[j][k]<=1e9)
					{
						for(int y = 1, x = 1; y <= q; y++, x *= 3)
						{
							if((i / x % 3 == 0 && k == s[y] || i / x % 3 == 1 && k == t[y]) && r[y] >= dp[i][j] + dis[j][k])
							{
								dp[i + x][k] = min(dp[i + x][k], max(dp[i][j] + dis[j][k], l[y]));
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < tot; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(dp[i][j] <= 1e9)
			{
				int tmp = i, cnt = 0;
				while(tmp)
				{
					cnt += (tmp % 3 == 2);
					tmp /= 3;
				}
				ans = max(ans, cnt);
			}
		}
	}
	printf("%d\n",ans);	 
	return 0;
}