#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;
int main()
{
   int n,m;
   
	while (~scanf("%d %d",&m,&n))
	{
		int i,a[20001];
		int sum;
		sum=m+n;                      //输入到一个集合中
		for (i=0;i<m;i++)
			scanf ("%d",&a[i]);
		for (i=m;i<sum;i++)
			scanf ("%d",&a[i]);
		sort(a,a+n+m);
		printf ("%d",a[0]);                 //依次输出集合内元素
		for (i=1;i<sum;i++)
		{
			if (a[i]==a[i-1])           //当遇到与前一项相等数时，跳过
				continue;
			printf (" %d",a[i]);
		}
		printf ("\n");
	}

    
    return 0;
}