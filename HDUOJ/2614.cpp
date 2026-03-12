#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int vis[21];
int map[20][20];
int sum; int n;
void dfs(int k, int num,int time)
{
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0 &&map[k][i]>=time)
		{
			vis[i]=1;
			dfs(i,num+1,map[k][i]);
			vis[i]=0;
		}
		
	}
	sum=max(sum,num);
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>map[i][j];
			}
		}
		memset(vis,0,sizeof(vis));
		sum=0;
		vis[0]=1;
		dfs(0,1,0);
		cout<<sum<<"\n";
	}
	return 0;
}