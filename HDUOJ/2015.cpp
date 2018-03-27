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

int main()
{
	int i,a[102]={0},m,n,count=0,sum=0,flag=0;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
			a[i]=2*(i+1);
		for(i=0;i<n;i++)
		{
			sum+=a[i];
			count++;
			if(count==m)
			{
				if(flag==1) printf(" ");
				printf("%d",sum/m);
				sum=0; count=0;
				flag=1;
			}	
		}
		if(sum!=0)  printf(" %d",sum/count);
		printf("\n");
		sum=0; count=0; flag=0;
	}
	return 0;
}