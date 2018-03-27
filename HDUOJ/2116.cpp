#include<cstdio>
#include<algorithm>
using namespace std;
long long  a,b,m,n,Max,Min=0;
void solve(int n)
{
	long long ans=1;
	for(int i=1;i<n;i++) ans*=2;
	Min=-ans;
	Max=ans-1;
}
int main()
{
	while(~scanf("%I64d%I64d%I64d",&n,&a,&b))
	{
	        solve(n);
			if((a>=0&&b<=0)||(a<=0&&b>=0)) printf("WaHaHa\n");
			if(a>0&&b>0)
			{
				if(a>Max-b) printf("Yes\n");
				else printf("WaHaHa\n");
			}
			if(a<0&&b<0)
			{
				if(a<Min-b) printf("Yes\n");
				else printf("WaHaHa\n");	
			}
	}
	return 0;
}