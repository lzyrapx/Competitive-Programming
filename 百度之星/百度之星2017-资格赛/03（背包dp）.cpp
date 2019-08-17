#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in freopen("in.txt","r",stdin)
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--) 
const int maxn = 100005;
const int mod = 1e9+7;
const ll INF =1000000000LL*100000000LL;
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int a[maxn],b[maxn],c[maxn],d[maxn];
ll dp[12][1234];
int n,m,k,l,t;
ll getmax(ll a,ll b)
{
    return a>b?a:b;
}
ll getmin(ll a,ll b)
{
    return a>b?b:a;
}
int main()
{
     while(~scanf("%d%d",&n,&m))
     {
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i],&b[i]);
        } 
        for(int i=1;i<=m;i++){
            scanf("%d%d",&c[i],&d[i]);
        } 
        for(int k=0;k<=10;k++)
        {
               for (int i=1;i<=1000;i++) dp[k][i]=INF;
               for (int i=1;i<=1000;i++)
               {
                    for (int j=1;j<=m;j++)
                    {
                        if(d[j]>k) 
                        {
                            dp[k][i]=getmin(dp[k][i],dp[k][getmax(0,i-d[j]+k)]+c[j]);
                        }
                    }
                } 
         }    
   ll ans=0;
   for(int i=1;i<=n;i++)
   {
        ans+=dp[b[i]][a[i]];
        ans=getmin(ans,INF);
   }
    if(ans==INF)puts("-1");
       else printf("%I64d\n",ans);
 }
 return 0;
}
