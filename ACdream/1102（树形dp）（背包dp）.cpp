/*
* this code is made by LzyRapx
* Problem: 1102
* Verdict: Accepted
* Submission Date: 2017-07-10 11:53:04
* Time: 4MS
* Memory: 2056KB
*/
#include<bits/stdc++.h>
using namespace std;
struct edge{
    int nxt,y;
}tree[30005];
int n,m;
int all;
int dp[105];
int head[30005];
bool vis[3005];
int a[3005],b[3005],fa[3005];
void addedge(int x,int y)
{
    tree[all].nxt = head[x];
    tree[all].y = y;
    head[x] = all++;
}
void pre(int x,int p)
{
    fa[x] = p;
    for(int i=head[x];i!=-1;i=tree[i].nxt)
    {
        if(tree[i].y == p) continue;
        pre(tree[i].y,x);
    }
}
void dfs(int x,int z,int w)
{
    if(vis[x]==true)return;
    vis[x] = true;
    for(int i=w;i>=a[x];--i)
    {
        dp[i] = max(dp[i],dp[i-a[x]] + b[x]);
    }
    if(x==z)return;
    dfs(fa[x],z,w);
}
int main()
{
    int x,y,z,w;
    while(~scanf("%d%d",&n,&m))
    {
        memset(head,-1,sizeof(head));
        all = 0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            addedge(x,y);
            addedge(y,x);
        }
        pre(1,-1);
        while(m--)
        {
            scanf("%d%d%d%d",&z,&x,&y,&w);
            memset(vis,false,sizeof(vis));
            memset(dp,0,sizeof(dp));
            dfs(x,z,w);
            dfs(y,z,w);
            printf("%d\n",dp[w]);   
        } 
    }
    return 0;
 }