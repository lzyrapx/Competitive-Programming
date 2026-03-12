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
#include<algorithm>  
typedef long long LL;  
using namespace std; 
const int maxn=3000;
LL s[maxn];
int main()
{
    LL n,m,i;
	s[1]=1;
	for(i=3;i<=maxn;i+=2)
	{
		s[i]=s[i-2]+i*i;
	}
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%lld\n",s[n]);
	} 
    return 0;
}
