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
    long long int i,a[52],n;
    a[1]=1;a[2]=2;
    for(i=3;i<51;i++)
        a[i]=a[i-1]+a[i-2];
    while(~scanf("%d",&n))
    {
        printf("%lld\n",a[n]);
    }
	return 0;	
}

