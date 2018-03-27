#include<stdio.h>
int main()
{
	long long  s[51]={0,1};
	int i;
	for(i=2;i<=50;i++)
		s[i]=s[i-2]+s[i-1];
	int n;
	while(scanf("%d",&n)&&(n!=-1))
		printf("%I64d\n",s[n]);
	return 0;
	
}