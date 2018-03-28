//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string.h>
using namespace std;
typedef long long ll;
int dig[63];
ll dp[63][2][63];

ll dfs(int pos,bool have,int last,int flag)
{
    int i;
    if (pos < 0) return have;
    if (flag==0 && dp[pos][have][last]!=-1) return dp[pos][have][last];
    
    int n=flag ? dig[pos] : 9;
    ll ans=0;
    for(i=0;i<=n;i++)
    {
        if (last==4 && i==9) ans += dfs(pos-1,true,i,flag && (i==n));
        else ans+=dfs(pos-1,have,i,flag && (i==n));
    }
    if (flag==0)
    {
        dp[pos][have][last]=ans;
    }
    return ans;
}
ll solve(ll x)
{
	int len = 0; 
	while(x)
	{
		dig[len++] = x % 10;
		x /= 10;
	}
	return dfs(len-1,0,0,1);
}

int main()
{
	ll x;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%I64d",&x);
		printf("%I64d\n",solve(x));
	}
	return 0;
}