#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int M=1000000007;
const int maxn=100005,N=100000;
int n,m,fc[maxn],fi[maxn];
int pow(int a,int b)
{
    int s=1;
    for(;b;b>>=1,a=(LL)a*a%M)
        if(b&1)s=(LL)s*a%M;
    return s;
}

int C(int n,int k)
{
    if(k<0||k>n)return 0;
    return (LL)fc[n]*fi[k]%M*fi[n-k]%M;
}

int main()
{

    for(int i=fc[0]=1;i<=N;i++)
        fc[i]=(LL)fc[i-1]*i%M;
    fi[N]=pow(fc[N],M-2);
    for(int i=N;i;i--)
        fi[i-1]=(LL)fi[i]*i%M;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
    int ans=0;
    for(int i=0;i<=min(n,m);i++)
        ans=(ans+(LL)C(n-2,i)*C(m-2,i))%M;
    cout<<ans<<endl;
    }
    return 0;
}