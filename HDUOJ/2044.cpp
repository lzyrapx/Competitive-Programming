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
	long long int f[55];  
    f[1]=1;  
    f[2]=2;  
    for(int i=3;i<55;i++)  
    {  
        f[i]=f[i-1]+f[i-2];  
    }  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        int n,m;  
        scanf("%d%d",&n,&m);  
        printf("%lld\n",f[m-n]);  
    }  
	return 0;	
}