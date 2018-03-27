#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<algorithm>
typedef long long LL;
using namespace std;

LL a[100005],i,n,m,j,k,l;
int main()
{
	a[1]=1;a[2]=3;
	for(i=3;i<100002;i++)
	{
		if(i%3==0)
		a[i]=a[i-1]+i*i*i;
		else
		a[i]=a[i-1]+i;
	}
	while(scanf("%lld",&n)&&n>=0)
	{
		printf("%lld\n",a[n]);
	}
	return 0;
}