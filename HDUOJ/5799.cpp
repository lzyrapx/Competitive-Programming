#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
typedef long long LL;
int n,m,a[maxn],b[maxn];
struct Edge
{
    int v,next;
}edge[maxn*2];
int head[maxn],ne;
inline void add(int u,int v)
{
    edge[ne].v=v;
    edge[ne].next=head[u];
    head[u]=ne++;
}
int idx,L[maxn],R[maxn],dep[maxn],fa[maxn],is[maxn];
int st[maxn],stn,pos[maxn],b_cnt;
const int sz=200;
int dfs(int u,int pre)
{

    L[u]=++idx;
    is[idx]=u;
    dep[u]=dep[pre]+1;
    fa[u]=pre;
    int siz=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==pre)continue;
        siz+=dfs(v,u);
        if(siz>sz)
        {
            while(siz--)pos[st[--stn]]=b_cnt;
            b_cnt++;
        }
    }
    st[stn++]=u;
    R[u]=idx;
    return siz+1;
}
struct QUERY
{
    int l,r,block,a,b,idx;
    QUERY(int L=0,int R=0,int A=0,int B=0,int id=0)
    {
        l=L;
        r=R;
        if(l>r)swap(l,r);
        block=L/sz;
        a=A;
        b=B;
        idx=id;
    }
    bool operator <(const QUERY &p)const
    {
        return block!=p.block?block<p.block:r>p.r;
    }
}qr1[maxn],qr2[maxn];
bool cmpd(const QUERY &a,const QUERY &b)
{
    return pos[a.l]<pos[b.l]||(pos[a.l]==pos[b.l]&&L[a.r]>L[b.r]);
}
int num[maxn],dis[maxn],dlen;
LL res[maxn],ans[maxn];
inline void add(int u)
{
    res[num[b[u]]]-=a[u];
    ++num[b[u]];
    res[num[b[u]]]+=a[u];
}
inline void remove(int u)
{
    res[num[b[u]]]-=a[u];
    --num[b[u]];
    res[num[b[u]]]+=a[u];
}
bool in[maxn];
int cross;
inline void inv(int x) {
    if(in[x]) {
        in[x] = false;
        remove(x);
    }
    else {
        in[x] = true;
        add(x);
    }
}

//move x up
inline void move_up(int &x) {
    if(!cross) {
        if(in[x] && !in[fa[x]]) cross = x;
        else if(in[fa[x]] && !in[x]) cross = fa[x];
    }
    inv(x), x = fa[x];
}

//move a to b
void move(int a, int b) {
    if(a == b) return ;
    cross = 0;
    if(in[b]) cross = b;
    while(dep[a] > dep[b]) move_up(a);
    while(dep[b] > dep[a]) move_up(b);
    while(a != b) move_up(a), move_up(b);
    inv(a), inv(cross);
}
void read(int &x)
{
    char c;
    while(!isdigit(c=getchar()));
    x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';
}
char s[35];
void print(LL x)
{
    int con=0;
    do
    {
        s[con++]=x%10+'0';
        x/=10;
    }while(x);
    for(int i=con-1;i>=0;--i)putchar(s[i]);
}
/*
考虑链上的操作，我们用树上莫队来处理，因为很容易做到O(1)转移到相邻节点的状态。
考虑子树操作，可以启发式合并来维护答案，也可以先dfs序一下，然后再跑普通的莫队算法就好了。
*/
int main()
{
    /*
    int size = 256 << 20; // 256MB
    char *p = (char*)malloc(size) + size;
    __asm__("movl %0, %%esp\n" :: "r"(p));
    freopen("1.in","r",stdin);freopen("1.ans","w",stdout);*/
    int T,u,v;
    int op,l,r,A,B,q1,q2;
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas)
    {
        //cerr <<cas<<endl;
        ne=0;
        memset(head,-1,sizeof(head));
        //scanf("%d%d",&n,&m);
        read(n);read(m);
        for(int i=1;i<=n;++i)
        {
            //scanf("%d",&a[i]);
            read(a[i]);
            dis[i-1]=a[i];
        }
        sort(dis,dis+n);
        dlen=unique(dis,dis+n)-dis;
        for(int i=1;i<=n;++i)
            b[i]=lower_bound(dis,dis+dlen,a[i])-dis;
        //cout <<dlen<<endl;
        for(int i=2;i<=n;++i)
        {
            //scanf("%d%d",&u,&v);
            read(u);read(v);
            add(u,v);
            add(v,u);
        }
        idx=0;
        b_cnt=0;
        dfs(1,0);
        while(stn)pos[st[--stn]]=b_cnt;
        q1=q2=0;
        for(int i=0;i<m;++i)
        {
            //scanf("%d%d%d%d%d",&op,&u,&v,&A,&B);
            read(op);read(u);read(v);read(A);read(B);
            if(op==1)
                qr1[q1++]=QUERY(L[u],R[v],A,B,i);
            else
                qr2[q2++]=QUERY(u,v,A,B,i);
        }
        //for(int i=1;i<=n;++i)cout <<L[i]<<" "<<R[i]<<endl;
        //for(int i=1;i<=n;++i)cout <<dep[i]<<" "<<fa[i]<<endl;
        //for(int i=1;i<=n;++i)cout <<is[i]<<" is "<<a[is[i]]<<endl;
        sort(qr1,qr1+q1);
        memset(num,0,sizeof(num));
        memset(res,0,sizeof(res));
        for(int i=1;i<=n;++i)res[0]+=a[i];
        l=1,r=0;
        for(int i=0;i<q1;++i)
        {
            //cout <<qr1[i].l<<" "<<qr1[i].r<<endl;
            while(r<qr1[i].r)add(is[++r]);
            while(l<qr1[i].l)remove(is[l++]);
            while(r>qr1[i].r)remove(is[r--]);
            while(l>qr1[i].l)add(is[--l]);
            //for(int j=0;j<=n;++j)cout <<num[j]<<" ";cout <<endl;
            //for(int j=0;j<=n;++j)cout <<res[j]<<" ";cout <<endl;
            ans[qr1[i].idx]=__gcd(res[qr1[i].a],res[qr1[i].b]);
        }
        //cout <<"sequence"<<endl;
        sort(qr2,qr2+q2,cmpd);
        memset(num,0,sizeof(num));
        memset(res,0,sizeof(res));
        memset(in,0,sizeof(in));
        for(int i=1;i<=n;++i)res[0]+=a[i];
        l=r=1;
        add(1);
        in[1]=true;
        for(int i=0;i<q2;++i)
        {
            move(l,qr2[i].l);
            move(r,qr2[i].r);
            l=qr2[i].l;
            r=qr2[i].r;
            /*cout <<qr2[i].l<<" "<<qr2[i].r<<" "<<l<<" "<<r<<endl;
            for(int j=0;j<=n;++j)cout <<num[j]<<" ";cout <<endl;
            for(int j=0;j<=n;++j)cout <<res[j]<<" ";cout <<endl;*/
            ans[qr2[i].idx]=__gcd(res[qr2[i].a],res[qr2[i].b]);
        }
        printf("Case #%d:\n",cas);
        for(int i=0;i<m;++i)
        {
            print(ans[i]);puts("");
            //printf("%I64d\n",ans[i]);
        }
    }
    return 0;
}