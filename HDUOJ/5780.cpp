#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+5;
const int mod=1e9+7;
LL s[N];
int prime[N],phi[N];

void init() //É¸·¨ 
{
    phi[1]=1;
    for(int i=2;i<=N;++i)
	{
        if(!phi[i])
		{
            prime[++prime[0]]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=prime[0]&&i*prime[j]<=N;++j)
        {
        	if(i%prime[j])
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
            else	 
				phi[i*prime[j]]=phi[i]*prime[j];
		}
            
    }
    for(int i=1;i<=N;++i)
		 phi[i]=(phi[i]+phi[i-1])%mod;
    s[1] = s[0] = 1;
    for(int i = 2;i < N;i++)
    	 s[i] = s[mod%i]*(mod-mod/i)%mod;
}

LL q_mod(LL x,LL n)    //x^n:O(log(n))£»
{
    LL res=1;
    while(n)
    {
        if(n & 1)
            res=(res*x)%mod;
            n>>= 1;
        x=(x*x)%mod;
        
    }
    return res;
}
LL solve(LL q,LL n)
{
    if(q==1) return n;
    return (q_mod(q,n)-1)*s[q-1]%mod;
}

int main()
{
    init();
    int t,x,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&n);
        LL ans=0;
        for(int i=1,j;i<=n;i=j+1)
        {
            j = n/(n/i);
            LL sd = 2*phi[n/i]-1; 
            ans = (ans + sd * (q_mod(x,i) * solve(x,j-i+1)%mod -(j-i+1)) % mod) % mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}