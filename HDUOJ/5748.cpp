//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define N 1000010
using namespace std;
int n,a[N];
int b[N];
int cnt;
int s[N];
int f[N];
int query(int x)
{
	int ret =0;
	while(x){
		ret= max(ret,s[x]);
		x-= x&-x;
	}
	return ret;
}
void upd(int x,int y)
{
	while(x<=cnt)
	{
		s[x]=max(s[x],y);
		x+=x&-x;
	}
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	cnt=0;
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d",&a[i]);
    		b[++cnt]=a[i];
		}
		sort(b+1,b+cnt+1);
		cnt=unique(b+1,b+cnt+1)-b-1;
		for(int i=1;i<=n;i++)
		{
			a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
		}
		for(int i=1;i<=cnt;i++) s[i]=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=query(a[i]-1)+1;
			upd(a[i],f[i]);
			printf("%d%c",f[i],i==n?'\n':' ');
		}
	}
    return 0;
}