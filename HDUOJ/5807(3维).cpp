//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 50+10;
const int mod=998244353;
int MAX[3];
int MAXN[3];
int read()
{
	int v = 0, f = 0;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
ll dp[N][N][N];
int a[N][N];
int w[N];
int g[N][N][N];
int h[N][N][N];
int main()
{
  // freopen("in.txt","r",stdin);
	int t,n,m,k,q;
	int x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&q);
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		memset(a,0,sizeof(a));
		
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			a[y][x]=1;
		}
		for(int i=n;i>=1;--i)
			for(int j=n;j>=1;--j)
				for(int d=n;d>=1;--d){
				dp[i][j][d] = 1;g[i][j][d] = 0;h[i][j][d] = 0;
					for(int t=1;t<=n;t++){
						if(a[t][i]){
							( dp[i][j][d] += h[t][j][d]) %=mod;
						}
					}
					for(int t=1;t<=n;t++){
						if(a[t][j]){
							( h[i][j][d] += g[i][t][d] )%=mod;
						}
					}
					for(int t=1;t<=n;t++){
						if(a[t][d]){
							( g[i][j][d] += dp[i][j][t])%=mod;
						}
					}
					//²»ºÏ·¨ 
					if(abs(w[i]-w[j]) > k) dp[i][j][d] = 0;
					if(abs(w[i]-w[d]) > k) dp[i][j][d] = 0;
					if(abs(w[j]-w[d]) > k) dp[i][j][d] = 0;
				}
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			printf("%lld\n",dp[x][y][z]);
		}
	}
	return 0;
}