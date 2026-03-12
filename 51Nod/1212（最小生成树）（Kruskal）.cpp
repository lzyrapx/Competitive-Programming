#include <bits/stdc++.h>
using namespace std;
const int N=1234;
struct Edge{
    int u,v,w;
}e[N*N];
int p[N],vis[N],mst[N][N],d[N][N],w[N][N];
int n,m,mt;

int cmp(const Edge& a,const Edge& b)
{
    return a.w<b.w;
}

int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
int Kruskal()
{
    int i,j,x,y,sum=0;
    for(i=1;i<=n;i++)p[i]=i;
    sort(e,e+m,cmp);
    memset(mst,0,sizeof(mst));
    for(i=0;i<m;i++){
        x=find(e[i].u);
        y=find(e[i].v);
        if(x!=y){
            sum+=e[i].w;
            p[y]=x;
        //    mst[e[i].u][e[i].v]=mst[e[i].v][e[i].u]=1;  //MST中的边
        }
    }
    return sum;
}

int main()
{  
    cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	 }
	 cout<<Kruskal()<<endl;
    return 0;
}