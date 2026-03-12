#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000010;
const int mod = 1e9+7; 
int tot=0;
int check[N],mu[N],fib[N];
int prime[N];
int inv[N];
int g[N],f[N];
ll q_mod(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void mobius()
{
    mu[1]=1;
	int n=1000005;
    for(int i=2;i<=n;i++)
    {
        if(!check[i]){
            prime[++tot]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=tot&&i*prime[j]<=n;j++)
        {
            check[i*prime[j]]=1;
            if(!(i%prime[j]))
            {   
                mu[i*prime[j]]=0;
                break;
            }
            else mu[i*prime[j]]=-mu[i];
        }
    }
    
     
	for(int i=0;i<=n;i++){
		f[i]=g[i]=1;
	}
    fib[0]=0; fib[1]=1;
    for(int i=2;i<=n;i++)
    {
    	fib[i]=fib[i-1]+fib[i-2];
    	if(fib[i]>=mod) fib[i]-=mod;
	}
	
	for(int i=2;i<=n;i++){
    	inv[i]=q_mod(fib[i],mod-2);
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=i,k=1;j<=n;j+=i,k++)
		{
			if(mu[k]==1)
			{
				f[ j ] = 1LL * f[ j ] * fib[ i ] % mod;
				g[ j ] = 1LL * g[ j ] * inv[ i ] % mod;
			}
			else if(mu[k]==-1)
			{
				f[ j ] = 1LL * f[ j ] * inv[ i ] % mod;
				g[ j ] = 1LL * g[ j ] * fib[ i ] % mod;
			}
		}
	}
	for(int i=2;i<=n;i++){
		f[i] = 1LL * f[i] * f[i-1] % mod;
		g[i] = 1LL * g[i] * g[i-1] % mod;
	}
}
int t,n,m;
int solve()
{
	int ans = 1 ;
	for(int pos,i=1;i<=n;i=pos+1)
	{
		pos = min(n/(n/i),m/(m/i));
		ans = 1LL * ans * q_mod( 1LL * f[pos] * g[i-1] % mod,1LL * (n/i) * (m/i) % (mod-1)) % mod;
	}
	//cout<<"ans="<<ans<<endl; 
	return ans;
}

int main()
{
//	freopen("product5.in","r",stdin);
	mobius();
//	cout<<"init finish"<<endl;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(n>m)swap(n,m);
		int ans = solve();
		printf("%d\n",ans);
	}
	return 0;
}