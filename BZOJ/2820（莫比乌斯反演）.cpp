#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e7+5;
int T,n,m,tot,mu[N],g[N],sum[N],prime[N/3];
bool check[N];
void mobius()
{
    mu[1]=1;n=1e7+2;
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
            else 
			{
				mu[i*prime[j]]=-mu[i];
			}
        }
    }
    for(int i=1;i<tot;i++)
    {
    	for(int j=1;j*prime[i]<=n;j++)
    	{
    		sum[j*prime[i]] += mu[j];
		}
	}
    for(int i=1;i<=n;i++) sum[i] += sum[i-1];
}
ll calc(int n,int m)
{
    if(n>m) swap(n,m);
    ll ans=0;int pos=0;
    for(int i=1;i<=n;i=pos+1)
	{
        pos=min(n/(n/i),m/(m/i));
        ans+=(ll)(n/i)*(m/i)*(sum[pos]-sum[i-1]);
    }
    return ans;
}
int main()
{
    mobius();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        printf("%lld\n",calc(n,m));
    }
    return 0;
}