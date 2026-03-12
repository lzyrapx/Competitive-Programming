#include<stdio.h>
#include<iostream>
#include<algorithm>
typedef long long LL;
typedef unsigned long long uLL;
const int N=100010;
LL a[N]; 
int main()
{
	int n,t;
	LL R ,L;
	LL ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%I64d%I64d",&n,&L,&R);
		for(LL i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
		std::sort(a,a+n+1);
		/*
		LL res=a[n]+a[n-1];
		LL sd=std::max(L,res);
		ans=R-sd+1;
		*/
		LL l,r;
		for(LL i=n-1;i>=1;--i)
		{    
		   
			 l=a[i+1]-a[i]+1; 
			 r=a[i+1]+a[i]-1;
			if(l>R||r<L)continue;
			if(R>r) ans+=R-r;
			R=l-1;
			if(L>R)break; 
		}
		if(L<=R) ans+=R-L+1;
		
		printf("%I64d\n",ans); 
	
	}
}