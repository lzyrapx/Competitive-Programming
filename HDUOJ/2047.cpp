#include<iostream>
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
#define MAX 40

int main()
{
	LL ans[MAX+1];
	int i;ans[1]=3;ans[2]=8;
	for(i=3;i<=MAX;i++)
	{
		ans[i]=2*(ans[i-1]+ans[i-2]);
		while(cin>>i)
		{
			printf("%lld\n",ans[i]);
		}
	}
    return 0;
}