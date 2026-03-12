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
int f(int m,int n)
{
	int sum=0;
	int p=1;
	while(m)
	{
		sum+=(m%10)*p;
		p=p*n;
		m=m/10;
	}
	return sum;
}
int main()
{
    int n,x,y,sum;
    while(cin>>n)
    {
    	sum=0;
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d(%d)",&x,&y);
    		sum+=f(x,y);
    	}
    	printf("%d\n",sum);
    }
    return 0;
}