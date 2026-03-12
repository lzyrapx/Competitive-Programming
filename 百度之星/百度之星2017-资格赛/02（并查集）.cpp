#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in freopen("in.txt","r",stdin)
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--) 
const int mod = 1e9+7;
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
const int maxn = 3456;
int n,m;
int degree[maxn];
int fa[maxn];
int find(int x)
{
    return fa[x]==x?x: fa[x]=find(fa[x]);
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
      for(int i=1;i<=n;i++){
        fa[i]=i; degree[i]=0;
      }
      int cnt=0;
      for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u==v)continue;
        degree[v]+=w;degree[u]+=w;
        if(find(u)!=find(v)){
            fa[find(u)]=find(v);
            cnt++;
        }
      }
      if(cnt!=n-1){
        puts("0");continue;
      }
      int ans = degree[1];
      for(int i=2;i<=n;i++)ans=min(ans,degree[i]);
      printf("%d\n",ans);
    }
    return 0;  
}  