#include<iostream>
#include<cstdio>
typedef long long LL;

int qmod(LL a,LL b,int c)
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
	LL a,b;
	while(~scanf("%lld%lld",&a,&b)){
		printf("%d\n",qmod(a,b,10));
	}
	return 0;
}