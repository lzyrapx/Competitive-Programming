#include<stdio.h>
#include<string.h>
int main()
{
	int n,a,b,m,i;
	char x[100],y[100];
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%s%s",x,y);
			a=strlen(x);
			m=a/2;
			b=strlen(y);
			for(i=0;i<m;i++)
				printf("%c",x[i]);
			for(i=0;i<b;i++)
				printf("%c",y[i]);
			for(i=m;i<a;i++)
				printf("%c",x[i]);
			printf("\n");
		}
	}
	return 0;
}