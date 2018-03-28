#include<stdio.h>
int main()
{
	int i,n,a,b,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b)	
			printf("Scenario #%d:\nyes\n\n",i);
		else
			printf("Scenario #%d:\nno\n\n",i);
	}
	return 0;
}