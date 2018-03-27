#include<stdio.h>
int main()
{
	int n,m,i,t,x;
	int  s;
	while(scanf("%d%d",&n,&m)!=EOF)
	{	
		s=1;
		while(m--)
		{
			s=s*10;
			t=s/n;
			s=s%n;
		}
		printf("%d\n",t%10);
	}
	return 0;
}