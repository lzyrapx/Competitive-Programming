#include <bits/stdc++.h>
using namespace std;
const int MOD= 1000000007;
const int MAXN=1e7;
int phi[MAXN+5];
long long sum[MAXN+5];
long long k,n,m,p;
void GetEuler()
{
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(int i = 2;i <= MAXN;i++)
        if(!phi[i])
            for(int j = i;j <= MAXN;j += i)
            {
                if(!phi[j]) phi[j]=j;
                phi[j] = phi[j] / i * (i-1);
            }
    sum[1]=1;
    for(int i = 2;i <=MAXN; i++)
        sum[i] = (sum[i-1] + phi[i]) % MOD;
}
long long Get_K(long long n,long long m)
{
    if(m==0) return 0;
    if(m==1) return phi[n];
    if(n==1) return sum[m];
    if(phi[n]==n-1) return (phi[n]*Get_K(1,m)%MOD + Get_K(n,m/n))%MOD;
    for(int i=2;i<MAXN;i++)
        if(n%i==0)
            return (phi[i] * Get_K(n/i,m)%MOD + Get_K(n,m/i) ) % MOD;
}
long long PowMod(long long a,long long b, long long mod)
{
    long long ans = 1;
    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        a= (a*a)%mod;
        b>>=1;
    }
    return ans;
}
long long Cal(long long k, long long p)
{
    if( p == 2) return k&1; //mod φ(p)
    return PowMod(k, Cal(k,phi[p])+phi[p], p); //递归的计算ans，递归出口为 φ(p)=1
}
int main()
{
    GetEuler(); //打表 
    while(~scanf("%lld%lld%lld",&n,&m,&p))
    {
        k = Get_K(n,m);
        printf("%lld\n",Cal(k,p));
    }
}