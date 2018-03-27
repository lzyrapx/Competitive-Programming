#include <stdio.h>
int main()
{
	int t,a,max;
	while(scanf("%d",&t)!=EOF &&t!=0)
	{
		max=0;
		while(t--)
		{
			scanf("%d",&a);
			if(a>max)
			{
				max=a;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}