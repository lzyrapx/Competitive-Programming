#include <stdio.h>
int a[500001];
int main()
{
	int n,i,num,j;
	scanf("%d",&n);
	a[0]=a[1]=1;
	for(i=1;i<=500000/2;i++)
		for(j=i*2;j<=500000;j+=i)
			a[j]+=i;
	while(n--)
	{
		scanf("%d",&num);
		printf("%d\n",a[num]);
	}
	return 0;
}