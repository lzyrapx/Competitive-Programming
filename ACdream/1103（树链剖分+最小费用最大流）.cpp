/*
* this code is made by LzyRapx
* Problem: 1103
* Verdict: Accepted
* Submission Date: 2017-07-11 19:11:24
* Time: 652MS
* Memory: 2504KB
*/
#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
#define lson rt<<1
#define rson rt<<1 | 1
const int INF = 0x3f3f3f3f;
const int maxn = 510;
const int maxm = 4*(1000+2000+12);
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
struct MinCostMaxFlow{
    int head[maxn],pnt[maxm],cap[maxm];
    int flow[maxm],nxt[maxm],ecnt;
    ll cost[maxm];
    void init()
    {
        memset(head,-1,sizeof(head));
        ecnt = 0;
    }
    inline void addedge(int u,int v,int cp,ll co)
    {
        pnt[ecnt] = v; cap[ecnt] = cp;  cost[ecnt] = co;
        nxt[ecnt] = head[u]; head[u] = ecnt++;
         
        pnt[ecnt] = u; cap[ecnt] = 0;  cost[ecnt] = -co;
        nxt[ecnt] = head[v]; head[v] = ecnt++;
    }
    inline void clear()
    {
        memset(flow,0,sizeof(flow));
    }
    int pre[maxn],dis[maxn];
    bool vis[maxn];
    bool spfa(int s,int t)
    {
        memset(dis,INF,sizeof(dis));
        queue<int>que;
        que.push(s);
        dis[s] = 0;
        while(!que.empty())
        {
            int u =  que.front();
            que.pop();
            vis[u] = false;
            for(int i=head[u]; ~i; i=nxt[i])
            {
                int v = pnt[i];
                if(cap[i] > flow[i] && dis[v] > dis[u] + cost[i])
                {
                    dis[v] = dis[u] + cost[i];
                    pre[v] = i;
                    if(!vis[v])
                    {
                        vis[v] = true;
                        que.push(v);
                    }
                }
            }
        }
        return dis[t]!=INF;
    }
    ll MCMF(int s,int t)
    {
        ll Mincost = 0;
        while(spfa(s,t))
        {
            int ang = INF;
            for(int u = t; u != s; u = pnt[pre[u]^1])
            {
                ang = min(ang, cap[ pre[u] ] - flow[pre[u]]);
            }
            for(int u = t; u != s; u = pnt[pre[u]^1])
            {
                flow[pre[u]] += ang;
                flow[pre[u]^1] += ang;
            }
            Mincost += 1LL*dis[t] * ang;
        }
        return Mincost;
    }
}G;
 
struct Edge{
    int u,v,a,b,c,d;
    void Read()
    {
        //scanf("%d%d%d%d%d%d",&u,&v,&a,&b,&c,&d);  
        u=read(),v=read(),a=read(),b=read(),c=read(),d=read();
    }
}tree[maxn],edge[maxm];
 
int idx[maxm],pre[maxm],eid[maxm];
struct Solve{
    int n,m;
    int head[maxn],pnt[maxn*2],nxt[maxn*2],ecnt;
    int Hash[maxm];
    int dep[maxn],size[maxn],son[maxn],fa[maxn],top[maxn],SegId[maxn],tot;
    void init(){
        memset(head, -1, sizeof(head));
        ecnt = tot = 0;
    }
    inline void addedge(int u,int v,int i){
        pnt[ecnt] = v; idx[ecnt] = i; nxt[ecnt] = head[u]; head[u] = ecnt++;
        pnt[ecnt] = u; idx[ecnt] = i; nxt[ecnt] = head[v]; head[v] = ecnt++;
    } 
    struct Segment{
        struct node{
            int l,r,add;
            node(){};
            node(int l,int r,int add):l(l),r(r),add(add){}
        }p[maxn<<2];
         
        void build(int rt,int l,int r)
        {
            p[rt] = node(l,r,0);
            if(l==r)return ;
            int mid = (l + r)>>1;
            build(lson,l,mid);
            build(rson,mid+1,r);
        }
        void push_down(int rt)
        {
            if(p[rt].add != 0){
                p[lson].add += p[rt].add;
                p[rson].add += p[rt].add;
                p[rt].add = 0;
            }
        }
        void update(int rt,int l,int r,int val)
        {
            if(l <= p[rt].l && p[rt].r <= r){
                p[rt].add += val;
                return;
            }
            int mid =(p[rt].l + p[rt].r)>>1;
            if(l<=mid)update(lson,l,r,val);
            if(r>mid)update(rson,l,r,val);
        }
        void push_up(int rt)
        {
            if(p[rt].l==p[rt].r)
            {
                if(p[rt].l > 1)
                {
                    tree[ eid[ p[rt].l ] ].a += p[rt].add;
                }
                p[rt].add = 0;
                return ;
            }
            push_down(rt);
            push_up(lson);
            push_up(rson);
        }
    }ST;
    void dfs_first(int u,int f,int depth)
    {
        fa[u] = f, size[u] = 1, son[u] = -1, dep[u] = depth;
        int maxSize = 0;
        for(int i = head[u]; ~i; i = nxt[i])
        {
            int v = pnt[i];
             
            if(v == f)continue;
             
            pre[v] = i;
             
            dfs_first(v,u,depth + 1);
            size[u] += size[v];
            if(size[v] > maxSize)
            {
                maxSize = size[v],son[u] = v;
            }
        }
    }
    void dfs_second(int u,int header)
    {
        SegId[u] = ++tot, top[u] = header,eid[tot] = idx[pre[u]];
        if(son[u] == -1)return;
        if(son[u] != -1){
            dfs_second(son[u],header);
        }
        for(int i = head[u]; ~i ;i = nxt[i])
        {
            if(pnt[i] != fa[u] && pnt[i] != son[u])
            {
                dfs_second(pnt[i],pnt[i]);
            }
        }
    }
    inline void InitG()
    {
        G.init();
        for(int i = 1;i < n;i++)
        {
            Hash[i] = G.ecnt;
            Edge& e = tree[i];
            G.addedge(e.u, e.v, max(e.a , 0), e.d - e.c);
            G.addedge(e.u, e.v, INF, e.d + e.b);
        } 
        for(int i = 1;i <= m;i++)
        {
            Edge& e = edge[i];
            G.addedge(e.u, e.v, max(e.a , 0), e.d - e.c);
            G.addedge(e.u, e.v, INF, e.d + e.b);
        } 
        G.addedge(n + 1, 1, 0,0);
    }
    ll query(int u,int val)
    {
        ST.push_up(1);
        ll sum = 0;
         
        for(int i = 1;i < n;i++){
             
            G.cap[ Hash[i] ] = max(0,tree[i].a);
             
            sum += (ll)max(0,tree[i].a) * (ll)tree[i].c;
        }
         
        for(int i=1;i <= m;i++)
        {
            sum += (ll)max(0,edge[i].a) * (ll)edge[i].c;    
        }
        G.cap[G.ecnt - 2] = val;
        G.clear();
        return sum + G.MCMF(n + 1,u); 
    }
    void modify(int u,int v,int val)
    {
        int p = top[u], q = top[v];
        while(p!=q)
        {
            if(dep[p] < dep[q])
            {
                swap(p,q);
                swap(u,v);
            }
            ST.update(1,SegId[p],SegId[u],val);
            u = fa[p];
            p = top[u];
        }
         
        if(u != v)
        {
            if(dep[u] < dep[v]){
                swap(u,v);
            }
            ST.update(1, SegId[v] + 1, SegId[u],val);
        }
    }
    inline void work()
    {
        //scanf("%d%d",&n,&m);
        n=read(),m=read();
         
        init();
        /*tree*/
        for(int i = 1;i < n;i++){
            tree[i].Read();
            addedge(tree[i].u, tree[i].v, i);
        }
        for(int i = 1; i <= m;i++)
        {
            edge[i].Read();
        }
        /*----*/
        InitG();
         
        ST.build(1,1,n);
        dfs_first(1,-1,0);
        dfs_second(1,1);
         
    //  cout<<"finish"<<endl;
         
        int Q;
    //  scanf("%d",&Q);
        Q=read();
        int a,b,c;
        while(Q--)
        {
            char op[5];
            scanf("%s",op);
            if(op[0]=='Q')
            {
                //scanf("%d%d",&a,&b);
                a=read(),b=read();
            //  cout<<"scanf finish"<<endl;     
                printf("%lld\n",query(a,b));
            }
            else if(op[0]=='C')
            {
                //scanf("%d%d%d",&a,&b,&c);
                a=read(),b=read(),c=read();
                modify(a,b,c);
            }
        }
    }
}gao;
 
int main()
{
    gao.work();
     
    return 0;
 }