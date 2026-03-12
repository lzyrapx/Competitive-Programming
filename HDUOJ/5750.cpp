#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int isprime[100005]={0};
int prime[100005]={0};
int k=0;

int init()
{
	int i,j;
	
	for(i=2;i<100000;i++)
	{
		if(isprime[i]==0)
		{
			for(j=2;i*j<100000;j++)
				isprime[i*j]=1;
			prime[k]=i;
			k++;
		}
	}
	return 0;
}

int main()
{
	int t,i;
	int m,n;	
	scanf("%d",&t);
	init();
	while(t--)
	{
		scanf("%d%d",&m,&n);

		for(i=0;i<k;i++)
		{
			if(n*prime[i]>=m) break;
			if(n<prime[i]) break;
			if(n%prime[i]==0) break;
		}
		if(n*prime[i]>=m || n<prime[i]) i--;
		printf("%d\n",i+1);
	}
	return 0;
}
