#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
int a,b,c,d,k;
int tot;
int t;
int mu[maxn],prime[maxn],sum[maxn];
bool check[maxn] = {1,1};
void mobius()
{
	mu[1]=1;int n=50000;
    for(int i=2;i<=n;i++){
        if(!check[i]) prime[++tot]=i,mu[i]=-1;
        for(int j=1;j<=tot&&i*prime[j]<=n;j++){
            check[i*prime[j]]=1;
            if(i%prime[j]==0){mu[i*prime[j]]=0;break;}
            else mu[i*prime[j]]=-mu[i];
        }
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+mu[i];
}
int calc(int n,int m)
{
    if(n>m) swap(n,m);
    int ans=0,pos=0;
    for(int i=1;i<=n;i=pos+1)
	{
        pos=min(n/(n/i),m/(m/i));
        ans+=(n/i)*(m/i)*(sum[pos]-sum[i-1]);
    }
    return ans; 
} 
int main()
{
	mobius();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		a--;c--;
		int ans = calc(b/k,d/k) - calc(a/k,d/k) - calc(c/k,b/k) + calc(a/k,c/k);
		printf("%d\n",ans);
	}
	return 0;
} 