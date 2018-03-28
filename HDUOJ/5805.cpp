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
const int N = 100000+10;
int a[N];
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
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 1; i<=n; i++) scanf("%d",&a[i]);
		memset(MAX,0,sizeof(MAX));
	//	for(int i=0;i<3;i++)MAX[i] = 0;
		for(int i = 1; i < n ; i++){
			int tmp=max(a[i] - a[i+1] , a[i+1] - a[i] );
			for(int j=0;j<3;j++)
			{
				if(tmp>=MAX[j])
				{
					for(int k=2;k>j;--k){
						MAX[k]=MAX[k-1];
						MAXN[k]=MAXN[k-1];
					}
					MAX[j] = tmp ;
					MAXN[j] = i;
					break;
				}
			}
		}
		ll ans = 0;
		int tmp = 0;
		for(int j=0;j<3;j++) 
		{
			if(MAXN[j] != 1)
			tmp=max(tmp,MAX[j]);
		}	
		ans+=tmp;
		tmp = 0;
		for(int j=0;j<3;j++)
		{
			if(MAXN[j] != n-1)
			tmp=max(tmp,MAX[j]);
		}
		ans+=tmp;
		for(int i=2;i<n;i++){
			int tmp =max( a[i-1] - a[i+1] , a[i+1] - a[i-1]) ;
			for(int j=0;j<3;j++){
				if(MAXN[j] != i-1 && MAXN[j] !=i ){
					tmp=max(tmp,MAX[j]);
				}				
			}
			ans+=tmp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}