#include<bits/stdc++.h> 
#define LL  long long
#define mod 100
using namespace std;
int q_mod(int a,LL b)
{
	int ans=1;
	while(b){
		if(b&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	int t;
	while(~scanf("%d",&t)&&t){
		int cas=0;
		LL n;
		while(t--){
			scanf("%I64d",&n);
			printf("Case %d: %d\n",++cas,( q_mod(4,n-1)+q_mod(2,n-1) ) % mod);
		}
		printf("\n");
	}
	return 0;
}
