#include<stdio.h>
int C(int n,int m)
{
	long long a=1,b=1,i;
	for(i=1;i<=m;i++,n--)
	{
		b*=i;
		a*=n;
	}
	return a/b;
}
int main()
{
	int i,n;
	long long ans,a[13];
	a[0]=1;a[1]=0;a[2]=1;a[3]=2;
	for(i=4;i<=12;i++)
		a[i]=(i-1)*(a[i-1]+a[i-2]);
//	for(int n=1;n<=25;n++)
//	{
		while(scanf("%d",&n)!=EOF&&n!=0)
		{
			ans=0;
			for(i=0;i<=n/2;i++)
			ans+=a[i]*C(n,i);
			printf("%I64d\n",ans);
		}
//	}
	return 0;
}