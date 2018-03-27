#include<cstdio>
#include<algorithm>
using namespace std;
int a[999999];
int main()
{
	
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		printf("%d\n",a[(n+1)/2]);

	}
	return 0;
}