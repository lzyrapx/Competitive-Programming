#include <stdio.h>
#include <string.h>
int main()
{
	int n,m,i,j,c,k=0;
	char a[1001]={0};
	scanf("%d",&n);
	while(n--)
	{
		k++;
		scanf("%d",&m);
		gets(a);
		j=strlen(a);
		for(i=m;i<j;i++)
		{a[i]=a[i+1];}
		printf("%d%s\n",k,a);
	}
	return 0;
}