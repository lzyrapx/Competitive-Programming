#include<stdio.h>
using namespace std;
#define inf 0x3f3f3f3;
int map[1100][1100],dist[1100],vis[1100],t,s,d,n;
void Dijkstra(int u)//源点
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=map[u][i];
        vis[i]=0;
    }
    dist[u]=0;
    vis[u]=1;
    for(int i=1;i<=n;i++)
    {
        int pos=u,min=inf;//每次查找的时候都是从源点开始，pos为u
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dist[j]<min)
            {
                pos=j;
                min=dist[j];
            }
        vis[pos]=1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j] && dist[j]>dist[pos]+map[pos][j])
                dist[j]=dist[pos]+map[pos][j];
        }
    }

}
int main()
{

    while(scanf("%d%d%d",&t,&s,&d)!=EOF)
    {
        int home[1010],go[1010];
        for(int i=1;i<=1010;i++)
        for(int j=1;j<=1010;j++)
            map[i][j]=inf;
        n=0;
        int min=9999;
        int a,b,c;
        for(int i=1;i<=t;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(map[a][b]>c)
                map[a][b]=map[b][a]=c;
            if(a>n) n=a;
            if(b>n) n=b;
        }
        for(int i=0;i<s;i++)
            scanf("%d",&home[i]);
        for(int i=0;i<d;i++)
            scanf("%d",&go[i]);

        for(int i=0;i<s;i++)
        {
       	 	Dijkstra(home[i]);
        	for(int j=0;j<d;j++)
            	if(dist[ go[j] ]<min) min=dist[ go[j] ];

        }
        printf("%d\n",min);
    }
}
