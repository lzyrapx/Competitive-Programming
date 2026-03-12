
/*
//WA
#include<iostream>  
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long LL;

int mod(LL a,  LL b)
{
	int ans=a;
	while(a>b)
	{
		a=a%b;
		ans=a;
	}
	return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    LL n,m;
    int res;
    while(cin>>n>>m)
    {
    	res=mod(n,m);
    	printf("%d\n",res);
	}
	return 0;
}
*/
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define N 50000
char s[N];
int main()
{
    int mod,m;
    while(~scanf("%s %d",s,&m))
   {
       mod=0;
       for(int i=0;i<strlen(s);i++)
       mod=(mod*10+s[i]-'0')%m;
       printf("%d\n",mod);
   }
    return 0;
}