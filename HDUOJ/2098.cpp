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
int prime(int s)
{
	for(int i=2;i<=sqrt(s);i++)
	{
		if(s%i==0) return 0;
		 
	}
	return 1;
}
int main()
{
	int n;  int x,y;
	while(~scanf("%d",&n),n)
	{
		int t=0;
		/*for(int i=1;i<=n;i++)
		{
			if(i%2==1&&prime(i))
			{
				a[i]=1;
			}
		}*/	
		int ans=0;
		for(int i=3;i<n/2;i+=2)
		{
			
			if(prime(i)+prime(n-i)==2)
			ans++;
		}
		printf("%d\n",ans);
	
	}
	return 0;
}