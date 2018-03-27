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
int main()
{
	int a,b;
	while(cin>>a>>b&&a!=0&&b!=0)
	{
		int v=0,k=0;
		for(v=0;v<=99;v++)
			if((a*100+v)%b==0)
			{
			if(k==1)
					printf(" ");
				k=1;
			if(v<10)
				printf("0%d",v);
			else
					printf("%d",v);
			}
			printf("\n");
	}
    return 0;
}