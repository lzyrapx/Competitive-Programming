#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>

#define MAXN 3333
#define MAXM 444444//最好是边数的两倍
using namespace std;

template<class TN>
inline void kread(TN &x)
{
    x=0;
    char c;
    while(!isdigit(c=getchar()));
    do{
        x=x*10+c-'0';
    }while(isdigit(c=getchar()));
}

template<class TN,class... ARGS>
inline void kread(TN &first,ARGS& ... args)
{
    kread(first);
    kread(args...);
}

const long long INF=0x3f3f3f3f;

int n,m;

struct Edge{
    long long v;
    int to;
    int next;
    int re;
}edge[MAXM];//边
int head[MAXN],top;//邻接链表
int dist[MAXN];

typedef __gnu_pbds::priority_queue<pair<int,int>,less<pair<int,int>>,__gnu_pbds::pairing_heap_tag> Heap;
Heap pq;
Heap::point_iterator pqIterator[MAXN];

void init()//初始化链表
{
    top=0;
    memset(head,-1,sizeof(head));
}

void addEdge(int a,int b,long long v)//a->b,容量为v的边
{
    if(v==0)return;
    edge[top].v=v;
    edge[top].to=b;
    edge[top].re=top+1;
    edge[top].next=head[a];
    head[a]=top++;

    edge[top].v=v;
    edge[top].to=a;
    edge[top].re=top-1;
    edge[top].next=head[b];
    head[b]=top++;
}

int findST(int &s,int &t)//找到某一s点和t点间最小割
{
    for(int i=1;i<=n;i++)
    {
        if(head[i]!=-2)
        {
            dist[i]=0;
            pqIterator[i]=pq.push(make_pair(dist[i],i));
        }
    }//初始化
    while(pq.size()>1)
    {
        s=pq.top().second;pq.pop();
        pqIterator[s]=pq.end();
        for(int j=head[s];j!=-1;j=edge[j].next)
            if(pqIterator[edge[j].to]!=pq.end())
                pq.modify(pqIterator[edge[j].to],make_pair(dist[edge[j].to]+=edge[j].v,edge[j].to));
    }
    t=pq.top().second;pq.pop();
    return dist[t];//dist[t]为s-t最小割
}

void merge(int s,int t)//合并s和t点
{
    int i=head[t],next;
    while(i!=-1)
    {
        next=edge[i].next;
        edge[i].next=head[s];
        head[s]=i;
        edge[edge[i].re].to=s;
        i=next;
    }
    head[t]=-2;//标记t被合并
}

int StoerWagner()
{
    int mincut=INF,s,t;
    for(int i=1;i<n;i++)//最多合并n-1次
    {
        mincut=min(mincut,findST(s,t));
        if(mincut==0)return 0;//达到下限
        merge(s,t);
    }
    return mincut;
}

int work()
{
    init();
    int a,b;
    long long v;
    for(int i=0;i<m;i++)
    {
        kread(a,b,v);
        addEdge(a,b,v);
    }
    return StoerWagner();
}

int main()
{
    while(~scanf("%d%d",&n,&m))printf("%d\n",work());
    return 0;
}
