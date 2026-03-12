#include<bits/stdc++.h>
using namespace std;
const int maxn =1000020;
long long x[maxn];
long long y[maxn];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		long long p=(p+x[i])%n;
		if(p==0)
		{
			for(int j=1;j<=i;j++)
			{
				printf("%lld %lld\n",j,x[j]);
			}
		}
		else if(y[p])
		{
			for(int j=y[p]+1;j<=i;j++)
			{
				printf("%lld %lld\n",j,x[j]);
			}
			return 0;
		}
		else
		{
			y[p]=i;
		}
		
	}
	
	return 0;
 } 