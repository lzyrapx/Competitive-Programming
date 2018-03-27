
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;

int main() 
{
    int i,t,n;
	double a[20];
	scanf("%d",&t);
	a[1]=0;
	a[2]=1;
	for(i=3;i<=20;i++)
	{
	   a[i]=(i-1)*(a[i-1]+a[i-2]);  //´íÅÅÐò 
	}
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
		  a[n]/=i;
		}
		printf("%.2lf%c\n",a[n]*100,'%');
	}

	return 0;
} 