#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int dp[10010][30],num[10010];

int max(int a,int b)
{
	return a>b? a:b;
}

void RMQ_init(int n)
{
	int i,j;
	memset(dp,0,sizeof(dp));
	for(i=1;i<n;i++)
	dp[i][0]=num[i];
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=0;i+(1<<j-1)<n;i++)
		dp[i][j]=max(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
	}
}

int RMQ(int L,int R)
{
	int k=0;
	while((1<<(k+1))<=R-L+1) ++k;
	return max(dp[L][k],dp[R-(1<<k)+1][k]);
}

int main()
{
	int n,m,i,j;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		scanf("%d",&num[i]);
		RMQ_init(n);
		scanf("%d",&m);
		int L,R;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&L,&R);
			printf("%d\n",RMQ(L+1,R+1));
		}
	}
}