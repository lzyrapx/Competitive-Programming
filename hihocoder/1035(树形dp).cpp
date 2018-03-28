#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN=1000010;
typedef unsigned long long int ll65;
typedef long long int ll64;
typedef struct node
{
    struct node *next;
    int c0,c1,v;
}node;
node buf[2000010];
int bufsize=0;
bool vis[MAXN]={false};
node *head[MAXN]={NULL};
ll64 dp[MAXN][5];
int add(int u,int v,int c0,int c1){
    node *p=buf+bufsize++;
    p->v=v; p->c0=c0; p->c1=c1;
    p->next=head[u]; head[u]=p;
    p=buf+bufsize++;
    p->v=u; p->c0=c0; p->c1=c1;
    p->next=head[v]; head[v]=p;
    return 0;
}
int dfs(int u,int fa){
    node *p=head[u];
    for(;p!=NULL;p=p->next){
        int v=p->v;
        if(v==fa) continue;
        dfs(v,u);
        vis[u]|=vis[v];
    }

    if(vis[u]==true){
        ll64 tmp0=0,tmp2=0,tmp3=0,tmp41=0;
        int match=-1,match1=-1;
        ll64 ff1,t1=1LL<<50,t2=1LL<<50,ff2,f1,f2;
        f1=f2=t1=t2=1LL<<50;
        dp[u][0]=dp[u][1]=dp[u][2]=dp[u][3]=dp[u][4]=0LL;
        for(p=head[u];p!=NULL;p=p->next){
            int v=p->v;
            if(v==fa) continue;
            if(vis[v]==true){
                dp[u][1]+=dp[v][1]+ p->c0 * 2;
                tmp2=min(dp[v][1]+p->c0*2,dp[v][2]+p->c1*2);
                dp[u][2]+= tmp2;
                tmp0=min(tmp0,dp[v][0]-dp[v][1]-p->c0);
                tmp3=min(tmp3,p->c0+p->c1+dp[v][3]-tmp2);
                tmp41=min(tmp41, min(p->c0+dp[v][0],p->c1+dp[v][4])-tmp2);
                ff1=p->c0+dp[v][0]-tmp2;
                if(ff1<f1){
                    match1=v;
                    f2=f1;
                    f1=ff1;
                }else f2=min(ff1,f2);
                ff2=p->c0+p->c1+dp[v][3]-tmp2;
                if(ff2<t1){
                    match=v;
                    t2=t1;
                    t1=ff2;
                }else t2=min(ff2,t2);
            }
        }
        dp[u][0]=dp[u][1]+tmp0;
        dp[u][3]=dp[u][2]+tmp3;
        dp[u][4]=dp[u][2]+tmp41;
        dp[u][4]=min(dp[u][3],dp[u][4]);
        if(match==match1){
                dp[u][4]=min(dp[u][4],dp[u][2]+min(f1+t2,f2+t1));
        }else{
             dp[u][4]=min(dp[u][4],dp[u][2]+f1+t1);
        }

    }
    return 0;
}
int main()
{
    int n,m,i,j,k,u,v,c0,c1;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d %d %d",&u,&v,&c0,&c1);
        add(u,v,c0,c1);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d",&k);
        vis[k]=true;
    }

    dfs(1,-1);

    cout<<min(dp[1][0],dp[1][4])<<endl;
    return 0;
}