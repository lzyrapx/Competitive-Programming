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
const int N=10005,M=4000005;

int c[2][M],s[M],tot,rt[10],n,m,l,a[N],f[11][N];

void add(int &x,int k,int p,int t)
{
    if(!x)
        x=++tot,c[0][x]=c[1][x]=s[x]=0;
    s[x]+=t;
    if(k<0)
        return;
    if(p&(1<<k))
        add(c[1][x],k-1,p,t);
    else
        add(c[0][x],k-1,p,t);
}

inline bool find(int &x,int k,int p,int t)
{
    if(!x||!s[x])
        return 0;
    if(k==-1)
        return 1;
    int w=p>>k&1;
    if(t&(1<<k))
        return find(c[w^1][x],k-1,p,t);
    if(s[c[w^1][x]])
        return 1;
    return find(c[w][x],k-1,p,t);
}

bool check(int k)
{
    tot=0;
    for(int i=0;i<m;i++)
        rt[i]=0;
    add(rt[0],29,0,1);f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(i-l-1>=0)
            for(int j=0;j<m;j++)
                if(f[j][i-l-1])
                    add(rt[j],29,a[i-l-1],-1);
        for(int j=m-1;~j;j--)
        {
            f[j+1][i]=find(rt[j],29,a[i],k);
            if(j!=m-1&&f[j+1][i])
                add(rt[j+1],29,a[i],1);
        }
    }
    return f[m][n];
}

void solve()
{
    cin>>n>>m>>l;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]^=a[i-1];
    int l=0,r=1073741824,Ans=0;
    while(l<=r)
    {
        int Mid=l+r>>1;
        if(check(Mid))
            Ans=Mid,l=Mid+1;
        else
            r=Mid-1;
    }
    cout<<Ans<<endl;
}

int main()
{
    int t,i=0;cin>>t;
    while(t--)
        printf("Case #%d:\n",++i),solve();
    return 0;
}