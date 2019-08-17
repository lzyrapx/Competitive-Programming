//大水题一道，排序一下，map一下，就完了

#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<algorithm>
typedef long long LL;
using namespace std;
const LL maxn=1e5+10;
const LL mod=9973;
char s[maxn];
map<string,int>q;
int main()
{
    int n;
    scanf("%d",&n);
    q.clear();
    for(int i=0; i<n; i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        sort(s,s+len);
        printf("%d\n",q[s]++);
    }
    return 0;
}
-------------------------------

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define LL __int64
const LL maxm=1e5+10;
const LL mod=9973;
char s[maxm];
map<string,int>q;
int dp[maxm];
void Init()//素数线性筛
{
    int vis[maxm];
    int isprime[maxm];
    int prime[maxm];
    int cnt=0;
    memset(vis,0,sizeof(vis));
    memset(isprime,0,sizeof(isprime));
    memset(prime,0,sizeof(prime));
    for(int i=2; i<=maxm; i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            vis[i]=1;
        }
        for(int j=0; j<cnt&&i*prime[j]<maxm; j++)
        {
            vis[i*prime[j]]=1;
        }
    }
    for(int i=0; i<cnt; i++)
    {
        isprime[prime[i]]=1;
    }
}
int POW(int n,int k)//n的k次方
{
    int sum=1;
    for(int i=1; i<=k; i++)
    {
        sum*=n;
    }
    return sum;
}
int quickmod(int a,int b,int mod)//快速
{
    int ans=1;
    a=a%mod;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    q.clear();
    for(int i=0; i<n; i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        sort(s,s+len);
        printf("%d\n",q[s]++);
    }
    return 0;
}