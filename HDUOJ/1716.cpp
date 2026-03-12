#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a[4],flag=0;
	while (~scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]))
	{
		if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0)break;
		if (flag!=0)
		{
			printf("\n");
		}
		flag=1;
		int sum=0,b[24];
		sort(a,a+4);
		do {
			if (a[0]!=0)
			{
				b[sum]=a[0]*1000+a[1]*100+a[2]*10+a[3];
				sum++;
			}
		}while(next_permutation(a,a+4));
		//格式恶心，PE一发 
		for (int j=0;j<sum;j++)
		{
			if (j+1==sum)
				printf("%d\n",b[j]);
			else if ((b[j]/1000==b[j+1]/1000))
				printf("%d ",b[j]);
			else
				printf("%d\n",b[j]);
		}
	}
	return 0;
}