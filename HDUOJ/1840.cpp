#include<stdio.h>
int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==0&&b==0&&c==0)printf("INF\n");
		else if(a==0&&b==0&&c!=0)printf("0\n");
		else if(a==0&&b!=0)printf("1\n");
		else if(a!=0&&b*b-4*a*c>0)printf("2\n");
		else if(a!=0&&b*b-4*a*c==0)printf("1\n");
		else if(a!=0&&b*b-4*a*c<0)printf("0\n");

	}
	return 0;
}