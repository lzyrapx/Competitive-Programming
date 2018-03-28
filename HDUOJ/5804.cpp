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
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ll sum = 0;
		ll a;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a);
			sum+=a;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&a);
			if(a>sum)putchar('1');
			else putchar('0');
		}
		printf("\n");
	}
	return 0;
}