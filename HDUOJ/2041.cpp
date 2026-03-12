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
	int N=0,M=0,i=0,sum=0;
	int a[41]={0};
	scanf("%d",&N);
	a[1]=1;
	a[2]=1;
	for(i=3;i<=40;i++)
	{
		a[i]=a[i-1]+a[i-2];
	} 
	while(N--)
	{
		scanf("%d",&M);
		printf("%d\n",a[M]);
	}
	return 0;	
}