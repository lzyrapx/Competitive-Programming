#include<stdio.h>
int main()
{
	int n,i,j,a;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		for(i=1;i<=a;i++)
		{
			for(j=1;j<a;j++)
				printf("%d ",i*j);
			printf("%d\n",i*a);
		}
	}
	return 0;
}