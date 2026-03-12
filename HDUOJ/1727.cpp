#include<stdio.h>
int main()
{
	int a,b;
	char s[10][10]={"\0","one","two","three","four","five","six","seven","eight","nine"};
	char p[10][10]={"\0","\0","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	char q[20][10]={"\0","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	while(~scanf("%d",&a))
	{
		if(a==0)
		{ 
			printf("zero\n");continue;
		}
		if(a/1000)
		{
			printf("%s thousand",s[a/1000]);
			b=a;
			a=a-b/1000*1000;
			if(a) printf(" and ");
		}
		if(a/100)
		{
			printf("%s hundred",s[a/100]);
			b=a;
			a=a-b/100*100;
			if(a) printf(" and ");
		}
		if(a<20) printf("%s",q[a]);
		else 
		{
			if(a>=20)
			{
				printf("%s",p[a/10]);
				b=a;
				a=a-b/10*10;
			}
			if(a) printf("-%s",s[a]);
		}
		printf("\n");
	}
	return 0; 
}