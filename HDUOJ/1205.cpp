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
#define max1 1000001
int a[max1]={0};
int main()
{
    __int64 sum;
	int N;
	int T;
	int i = 0;
	int max = 0;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &T);
		{
			i = 0;
			max = 0;
			sum = 0;
			while(T--)
			{
				scanf("%d", a+i);
				sum += a[i];
				max = a[i]>max? a[i]: max;  //求出最大值 
				i++;
			}
			if( max<=(sum - max + 1 )) //最多那堆<= 剩余的+1 
				printf("Yes\n");
			else
				printf("No\n");
		}
	}

	return 0;
}


