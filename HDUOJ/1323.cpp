#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;
int main()
{
	int a[110],num=1,i,j;
	while(~scanf("%d",&a[num]),a[num])
	{
		num++;
	}
	printf("PERFECTION OUTPUT\n");
	for(i=1;i<num;i++)  //i不用等于num，因为最后输入的数为0 
	{
		int sum=0;
		for(j=1;j<=a[i]/2;j++)
		{
			if(a[i]%j==0)     //求出比该数小的所有公约数，比如8有1,2,4,此时为DEFICIENT
			{
				sum+=j;
			}
		} 
		if(sum==a[i])
		printf("%5d  PERFECT\n",a[i]);
		else if(sum>a[i])
		printf("%5d  ABUNDANT\n",a[i]);
		else 
		printf("%5d  DEFICIENT\n",a[i]);
	}
	printf("END OF OUTPUT\n");
	return 0;

}