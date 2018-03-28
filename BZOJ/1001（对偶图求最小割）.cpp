#include<iostream>
#include<cstdio>
#include<cstring>
#define T n*(m-1)+(n-1)*m+(n-1)*(m-1)-n*m+3
using namespace std;
const int N=2001000;
int n,m,point[N],next[N*3],tot=1,ans,dis[N],l[10000000];
struct S{
    int st,en,va;
}aa[N*3];
bool f[N];
inline void add(int x,int y,int z)
{
    tot+=1,next[tot]=point[x];point[x]=tot;
    aa[tot].st=x;aa[tot].en=y;aa[tot].va=z;
    tot+=1,next[tot]=point[y];point[y]=tot;
    aa[tot].st=y;aa[tot].en=x;aa[tot].va=z;
}
inline int SPFA(int x,int y)
{
    int h=1,t=1,u,i;
    memset(dis,127/3,sizeof(dis));
    memset(f,1,sizeof(f));
    l[h]=x;dis[x]=0;
    while(h<=t){
        u=l[h];
        f[u]=true;
        for(i=point[u];i;i=next[i])
          if(dis[aa[i].en]>dis[u]+aa[i].va){
            dis[aa[i].en]=dis[u]+aa[i].va;
            if(f[aa[i].en]){
                f[aa[i].en]=false;
                t+=1;
                l[t]=aa[i].en;
            }
          }
        h+=1;
    }
    return dis[y];
}
int main()
{
    int i,j,x,y,z;
    scanf("%d%d",&n,&m);
    ans=210000000;
    for(i=1;i<=n;++i)
      for(j=1;j<m;++j){
        scanf("%d",&x);
        if(n==1) ans=min(ans,x);
        if(i==1) add(1,j*2+1,x);
        else if(i==n) add((i-2)*(m-1)*2+j*2,T,x);
        else add((i-2)*(m-1)*2+j*2,(i-1)*(m-1)*2+j*2+1,x);
      }
    for(i=1;i<n;++i)
      for(j=1;j<=m;++j){
        scanf("%d",&x);
        if(m==1) ans=min(ans,x);
        if(j==1) add((i-1)*(m-1)*2+2,T,x);
        else if(j==m) add(1,i*(m-1)*2+1,x);
        else add((i-1)*(m-1)*2+(j-1)*2+1,(i-1)*(m-1)*2+j*2,x);
      }
    for(i=1;i<n;++i)
      for(j=1;j<m;++j){
        scanf("%d",&x);
        add((i-1)*(m-1)*2+j*2,(i-1)*(m-1)*2+j*2+1,x);
      }
    if(n==1&&m==1) ans=0;
    if(n==1||m==1) printf("%d\n",ans);
    else printf("%d\n",SPFA(1,T));
    return 0;
}