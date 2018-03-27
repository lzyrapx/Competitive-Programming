#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
	LL t; LL a,b; LL ans;
	cin>>t;
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		ans=(LL)(a+b)%100;
		printf("%lld\n",ans);
	}
	return 0;
}