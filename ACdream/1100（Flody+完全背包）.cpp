/*
* this code is made by LzyRapx
* Problem: 1100
* Verdict: Accepted
* Submission Date: 2017-06-21 01:21:54
* Time: 64MS
* Memory: 1736KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+10;
int dis[123][123];
int x[123];
int w[123];
int t[123];
ll dp[1234];
int n,m,T;
//先Floyd求最短路径，再完全背包 
int main()
{
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>w[i]>>t[i];
	}
	memset(dis,31,sizeof(dis));
	
	for(int i=0;i<=n;i++)dis[i][i] = 0;
	
	for(int i=0;i<m;i++)
	{
		int u,v,cost;
		cin>>u>>v>>cost;
		dis[u][v] = min (dis[u][v],cost);//两点间的路径可能有多条 
	}
	for(int k=0;k<=n;k++){//Folyd 
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	memset(dp,0,sizeof(dp));
	int cost = 0;
	for(int i=0;i<=n;i++)//完全背包 
	{
		for(int j = T;j>=0;--j)
		{
			//在背包前，物品的容量得加上到这个物品的距离
			cost = j + dis[0][i];
			for(int k = 0;k <= x[i];k++)
			{
				if(cost + k * t[i] > T) break;
				//吃或不吃 
				dp[cost + k * t[i]] = max(dp[cost + k * t[i]],dp[j] + k * w[i]);
			}
		 } 
	}
	cout<<dp[T]<<endl;
	return 0;
}