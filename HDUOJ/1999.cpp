#include<iostream>
#include <stdio.h>
using namespace std; 
#define N 500010
__int64 a[N];
int ans[1010];
//一个数 n与任何数的因子和都不相等，那么n就叫做不可摸数
void init ()
{
	for (int i=1; i<N/2; ++i)
		for ( int j=i*2; j<N; j+=i)
			a[j] += i;  
			
		for (int i=0; i<N; i++)
			if (a[i]<=1000)
				ans[a[i]] = 1;
}
int main ()
{
	int n, i, t;
	scanf ("%d", &t);
	init();
	while (t --)
	{
		scanf ("%d", &n);
		if (ans[n])
			printf ("no\n");
		else
			printf ("yes\n");
	}
	return 0;
}