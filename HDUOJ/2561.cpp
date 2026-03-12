#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,a[101],l;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&l);
		for(int i=0;i<l;i++)
			scanf("%d",&a[i]);
		sort(a,l+a);
		printf("%d\n",a[1]);
	}
	return 0;
}