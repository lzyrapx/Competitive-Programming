//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int ans=0;
		int d =1 <<(min(m,30));
	    while(n)
	    {
	    	ans+=n/d;
	    	n-=n/d*d;
	    	d/=2;
		}
		printf("%d\n",ans);
	}
    return 0;
}