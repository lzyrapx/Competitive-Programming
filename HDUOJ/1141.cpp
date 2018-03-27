#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
//求n! < 2^bit最大的n，其中bit为计算机位数, 求 n。
//两边对数：log(1) + log(2) +...+ log(n) < bit* log(2)。
int main()
{
	int n; int bit;
	while(~scanf("%d",&n),n)
	{
		int time=(n-1960)/10;
		bit=pow(2.0,1.0*(time+2));
	 double sum=0; int i=1;
    while(1)
    {
		sum+= log10(i*1.0);	
		if(sum>bit*log10(2.0))
		 break;
		i+=1;
	
   }
		printf("%d\n",i-1);
	}
	return 0;
}