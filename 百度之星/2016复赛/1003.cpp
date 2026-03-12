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

const int N=50005;

map<int,int> H;

int t[N],c,n,m,x[N],y[N],d[N],z[N],val1[N],val2[N];

void solve()
{
    m=c=0;cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&x[i],&y[i],&z[i],&d[i]);
        t[++m]=y[i]-z[i];t[++m]=x[i]+z[i]+1;
    }
    sort(t+1,t+m+1);H.clear();
    for(int i=1;i<=m;i++)
        if(!H.count(t[i]))
            H[t[i]]=++c;
    memset(val1,0,sizeof val1);memset(val2,0,sizeof val2);
    for(int i=1;i<=n;i++)
        if(y[i]-z[i]<=x[i]+z[i])
        {
            int t1=H[y[i]-z[i]],t2=H[x[i]+z[i]+1];
            if(d[i]==1)
                val1[t1]++,val1[t2]--;
            else
                val2[t1]++,val2[t2]--;
        }
    int Max=0,Ans=0;
    for(int i=1;i<=c;i++)
    {
        val1[i]+=val1[i-1];val2[i]+=val2[i-1];
        Max=max(Max,val1[i]);
        Ans=max(Ans,Max+val2[i]);
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