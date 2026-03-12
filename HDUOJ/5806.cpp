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
const int N = 200000+10;
int a[N];
int MAX[3];
int MAXN[3];

int read()
{
	int v = 0, f = 1;
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
	int t,n,m,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int num=0, r=0 ;
	    ll ans=0;
	    for(int i=1;i<=n;i++){
	    	while(num < k && r < n){
	    		r++;
	    		/*
	    		if(a[r]>=m)
	    		num++;
	    		*/
	    		num += a[r]>=m;
	    	//	printf("num=%d\n",num);
	    	//	printf("a[r]=%d\n",a[r]);
	    	//	printf("m=%d\n",m);
			}
			if(num < k) break;
			ans += n-r+1;
			num-= a[i]>=m;
		}
		printf("%lld\n",ans);
	}
	return 0;
}