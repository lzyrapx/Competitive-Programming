#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

typedef long long LL;
const int N=15,M=36384,Mod=1000000009;

int n,m,k,f[N][M],g[M],Num[M],p2[M];

void solve()
{
    cin>>n>>m>>k;
    memset(g,0,sizeof g);
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;u--;v--;
        for(int j=0;j<(1<<n);j++)
            if(j&(1<<u)&&j&(1<<v))
                g[j]++;
    }
    memset(f,0,sizeof f);
    for(int s=0;s<(1<<n);s++)
    {
        Num[s]=p2[g[s]];
        int p=s&-s;
        for(int t=s&(s-1);t;t=(t-1)&s)
            if(t&p)
                Num[s]=(Num[s]-p2[g[s^t]]*(LL)Num[t])%Mod;
        Num[s]=(Num[s]+Mod)%Mod;f[1][s]=Num[s];
    }
    for(int i=1;i<k;i++)
        for(int s=1;s<(1<<n);s++)
            if(Num[s])
            {
                int p=s&-s,all=((1<<n)-1)^s^(p-1);
                for(int t=all;t;t=(t-1)&all)
                    f[i+1][s^t]=(f[i+1][s^t]+f[i][t]*(LL)Num[s])%Mod;
            }
    cout<<f[k][(1<<n)-1]<<endl;
}

int main()
{
    p2[0]=1;
    for(int i=1;i<M;i++)
        p2[i]=p2[i-1]*2%Mod;
    int t,i=0;cin>>t;
    while(t--)
        printf("Case #%d:\n",++i),solve();
    return 0;
}