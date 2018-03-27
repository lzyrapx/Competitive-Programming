#include<iostream>
#include<cstdio>
int qmod(long long a,long long b,int c)
{
	int ans=1;
	a=a%c;
	while(b>0){
		if(b&1)
		ans=(ans*a)%c;
		b=b>>1;
		a=(a*a)%c;
	}
	return ans;
}
int main()
{
	int n;  long long t;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld",&t);
		printf("%d\n",qmod(t,t,10));
	}
	
	return 0;
}