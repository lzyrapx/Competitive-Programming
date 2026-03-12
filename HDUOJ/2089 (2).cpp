//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
typedef long long ll;

int dig[31];
int dp[31][31][2];

int dfs(int pos, int last, int flag)//last: 上一位 
{
	if(pos < 0 && dig[pos]!=4)return 1; 
	if(flag==0 && dp[pos][last][flag]!=-1) return dp[pos][last][flag];
	int ans=0;
	int n = flag ?dig[pos] : 9;
	for(int i=0;i<=n;i++)
	{
		if(i==4||( last && i==2)) continue;
		else ans+= dfs(pos-1,i==6,i==n&&flag);
	}
	if(flag==0 && dp[pos][last][flag]!=-1)
	dp[pos][last][flag] = ans;
	return ans;
	
}

int solve(int x)
{
	int len = 0;
	while(x)
	{
		dig[len++] = x % 10;
		x /= 10;
	}
	return dfs(len-1,0,1);
}

int main()
{
	int x,y;
	memset(dp,-1,sizeof(dp));
	while(~scanf("%d %d",&x,&y))
	{
		if(x==0&&y==0) return 0;
		printf("%d\n",solve(y) - solve(x-1));
	}
	return 0;
}