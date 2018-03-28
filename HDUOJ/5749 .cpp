//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<algorithm>
#define N 1010
using namespace std;
int n,m;
int a[N][N];
int stk[N],top;
int L[N][N],R[N][N],U[N][N],D[N][N];
int readint()
{
	char c;
	while((c=getchar())&&!(c>='0' && c<='9'));
	int ret= c- 48;
	while((c=getchar())&&( c>='0' && c<='9'))
	ret = ret * 10 + c-48;
	return ret;
}
unsigned int calc(int l,int x,int r)
{
	unsigned int d1=r-x+1;
	unsigned int d2=x-l+1;
	unsigned int ret=d1 * (d1+1) / 2 * d2 + d2* (d2-1)/2 *d1;
	return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=m;j++)
    		{
    			a[i][j]=readint();
			}
		}
		for(int i=1;i<=n;i++)
		{
			top=0;
			for(int j=1;j<=m;j++)
			{
				while(top && a[i][stk[top-1]] > a[i][j])
				--top;
				if(top==0) L[i][j]=1;
				else L[i][j]=stk[top-1]+1;
				stk[top++]=j;
			}
		}
		for(int i=1;i<=n;i++)
		{
			top=0;
			for(int j=m;j>=1;--j)
			{
				while(top && a[i][stk[top-1]] > a[i][j])
				--top;
				if(top==0) R[i][j]=m;
				else R[i][j] = stk[top-1] - 1;
				stk[top++] = j;
			}
		}
		for(int i=1;i<=m;i++)
		{
			top=0;
			for(int j=1;j<=n;j++)
			{
				while(top && a[stk[top-1]][i] < a[j][i])
				--top;
				if(top==0) U[j][i]=1;
				else U[j][i] = stk[top-1]+1;
				stk[top++]=j;
			}
	  }
	  for(int i=1;i<=m;i++)
	  {
			top=0;
			for(int j=n;j>=1;--j)
			{
				while(top && a[stk[top-1]][i] < a[j][i])
				--top;
				if(top==0) D[j][i]=n;
				else D[j][i] = stk[top-1]-1;
				stk[top++]=j;
			}
		}
		unsigned int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				ans += (unsigned int)a[i][j]*calc(L[i][j],j,R[i][j])*calc(U[i][j],i,D[i][j]);
			}
		}
		printf("%u\n",ans);
	}
    return 0;
}