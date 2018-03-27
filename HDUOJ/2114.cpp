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
//数学公式：1^3+2^3+3^3+....n^3=[n(n+1)/2]^2 
int main()
{
	LL n,s;
	while(~scanf("%lld",&n))
	{
		s=(n*(n+1)/2%10000)*(n*(n+1)/2%10000)%10000;
		printf("%04lld\n",s);
	}
	return 0;
} 