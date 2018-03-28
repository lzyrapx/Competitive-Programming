#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod =1e9+7;
int n,k;
//http://sunshine-cfbsl.com/2017/04/08/hdu5628-clarke-and-math/
ll f[100010];
ll ans[100010];
ll tmp[100010],x[100010];
void dirichlet(ll *ans, ll *x){
	
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i*i<=n;i++)
	{
		tmp[i*i] += ans[i]*x[i]%mod; if(tmp[i*i]>=mod) tmp[i*i]%=mod;
		for(int j=i+1;i*j<=n;j++)
		{
			tmp[i*j] += ans[i]*x[j]%mod; if(tmp[i*j]>=mod) tmp[i*j]%=mod;
			tmp[i*j] += ans[j]*x[i]%mod; if(tmp[i*j]>=mod) tmp[i*j]%=mod;	
		} 
	}
	for(int i=1;i<=n;i++)
	{
		ans[i] = tmp[i];
	}
}
 
void qpower(){
	
	while(k)
	{
		if(k&1) dirichlet(ans,x);
		k>>=1;
		dirichlet(x,x); 
	}
	dirichlet(ans,f);//乘 f 
} 
void solve()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
		ans[i] = 0;
		x[i] = 1;
	}
	ans[1] = 1;
	qpower();

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k); 
		solve();
		for(int i=1;i<n;i++){
			printf("%lld ",ans[i]);
		}
		printf("%lld\n",ans[n]);
	}
	return 0;
}