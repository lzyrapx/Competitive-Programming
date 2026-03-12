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

const int N=50;

int n,m,xmin,xmax,d[N],t[N],f[N][N],g[N][N][N],Fa[N],Fb[N];
map<int,int> H;

void solve()
{
    cin>>n>>m>>xmin>>xmax;
    H.clear();
    for(int i=1;i<=n;i++)
        cin>>t[i];
    for(int i=1;i<=m;i++)
        cin>>d[i],H[d[i]]=1;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            f[i][j]=1e9;
    for(int i=n-1;i>=1;i--)
    {
        for(int D=1;D<=m;D++)
        {
            for(int j=i+1;j<=n;j++)
                for(int k=0;k<=xmax;k++)
                    g[k][i][j]=1e9;
            for(int j=i+1;j<=n;j++)
            {
                if(t[j]-t[i]==d[D])
                    g[2][i][j]=min(g[2][i][j],f[i+1][j-1]+1);
                for(int k=0;k<xmax;k++)
                    if(g[k][i][j]<=n)
                        for(int h=j+1;h<=n;h++)
                            if(t[j]+d[D]==t[h])
                                g[k+1][i][h]=min(g[k+1][i][h],g[k][i][j]+f[j+1][h-1]);
            }
            for(int j=i+1;j<=n;j++)
                for(int k=xmin;k<=xmax;k++)
                    f[i][j]=min(f[i][j],g[k][i][j]);
        }
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                f[i][k]=min(f[i][k],f[i][j]+f[j+1][k]);
    }
    memset(Fa,0,sizeof Fa);
    memset(Fb,0,sizeof Fb);
    for(int i=1;i<=n;i++)
    {
        if(Fa[i-1]>Fa[i]||(Fa[i-1]==Fa[i]&&Fb[i-1]<Fb[i]))
            Fa[i]=Fa[i-1],Fb[i]=Fb[i-1];
        for(int j=i+1;j<=n;j++)
            if(f[i][j]<=n)
            {
                int fa=Fa[i-1]+j-i+1,fb=Fb[i-1]+f[i][j];
                if(fa>Fa[j]||(fa==Fa[j]&&fb<Fb[j]))
                    Fa[j]=fa,Fb[j]=fb;
            }
    }
    cout<<Fa[n]<<" "<<Fb[n]<<endl;
}

int main()
{
    int t,i=0;cin>>t;
    while(t--)
        printf("Case #%d:\n",++i),solve();
    return 0;
}