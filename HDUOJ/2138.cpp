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
int prime (int n)
{
	int i;
	if(n==2||n==3)return 1;
	else if(n==0||n==1)return 0;
	else 
	for(i=2;i<=sqrt((double)n);i++)
		if(n%i==0)return 0;
         return 1; 	
}
int main()
{
    int t,a,sum,n;
	while(~scanf("%d",&t))
	{
		sum=0;
		while(t--)
		{
			scanf("%d",&n);
			getchar();
			if(prime(n))
			sum++;
		}
		printf("%d\n",sum);
	} 
    return 0;
}
