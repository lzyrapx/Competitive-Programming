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
	int t;
	cin>>t;
	while(t--)
	{
		LL n,s,d;
		cin>>n;
     	s=n*n*n;
		d=(n+1)*(n+1)*(n+1);
		printf("%lld %lld\n",s,d);
	}
	return 0;
} 