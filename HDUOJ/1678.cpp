#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{	
    return x>y;  
}
int main()
{	int t,n,i,sum;
	int a[20005];
	scanf("%d",&t);
	while(t--)
	{	scanf("%d",&n);sum=0;
		for(i=1;i<=n;i++)
		{	scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1,cmp);  //注意要从大到小排序，如果从小到大就会忽略掉不是3倍数，却又很大的数
		for(i=3;i<=n;i+=3)
		{	sum+=a[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}