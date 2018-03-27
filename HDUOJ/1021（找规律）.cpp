#include<cstdio>
int main()
{
	int f1,f2,fn,i,n;
	
	while (scanf("%d",&n)==1)
	{
		f1=7,f2=11;
		for (i=2;i<=n;i++)
		{
			fn=(f1+f2)%3;
			f1=f2%3;
			f2=fn%3;
		}
		if (fn%3==0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
}

