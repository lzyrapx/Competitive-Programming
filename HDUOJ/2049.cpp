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
    LL n,m,c,i;
    scanf("%d",&c);
	while(c--)
	{
		LL a[31];
		a[0]=a[1]=0;a[2]=1,a[3]=2;
		for(i=4;i<30;i++)
			a[i]=(i-1)*(a[i-1]+a[i-2]);
		LL sum1,sum2;
		sum1=sum2=1;
		scanf("%lld%lld",&n,&m);
		for(i=n;i>n-m;i--)
			sum1*=i;
		for(i=2;i<=m;i++)
			sum2*=i;
		printf("%lld\n",sum1/sum2*a[m]);
		
	}
	return 0;
} 