#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;
#define MaxN 10010
#define MaxInt 20000000
int map[MaxN][MaxN],dist[MaxN];
bool mark[MaxN];
int main()   //dijkstra
{
	int n,start,end;
   int min1,minj,temp;
   int a,b,c;
   while(~scanf("%d%d",&end,&n)) 
   {
   	  if(end==0&&n==0)break;
   	   start=1;
   	for(int i=1;i<=end;i++){
   		for(int j=1;j<=end;j++){
   			map[i][j]=map[j][i]=MaxInt;
   		}
   	}
   	for(int i=0;i<n;i++){
   		scanf("%d%d%d",&a,&b,&c);
   		map[a][b]=map[b][a]=c;  
   	}
   	for(int i=1;i<=end;i++) //初始化 
   	dist[i]=MaxInt;
   	memset(mark,0,sizeof(mark));
   	
   	dist[start]=0;    //把起点并入集合，搜索时即可从起点寻找到第一条最短的边
   	for(int i=1;i<=end-1;i++){    //查找到原集合的最短的边
   		min1=MaxInt;
   		  for(int j=1;j<=end;j++){   //每并入一个点都要对原来的边进行修正， 
			                        //保证任意时刻源点到目标点的距离都是最短的			                        
			  if(mark[j]==0&&dist[j]<min1)
			  {
			  	min1=dist[j];
			  	minj=j;
			  }
   	  }
   	  mark[minj]=1;
   	  for(int j=1;j<=end;j++){
   	  	if(mark[j]==0&&map[minj][j]>0){
   	  		temp=dist[minj]+map[minj][j];
   	  		 if(temp<dist[j])
			   dist[j]=temp;
   	  	 }    	  
		}
       }
       printf("%d\n",dist[end]);
   }
   
    return 0;
}

-----------
//-----spfa----
#include <iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#define INF 0x7ffffff
#define N 110

using namespace std;

int d[N],v[N],q[N],n,m,mp[N][N];

int spfa(int s,int t)
{
    for(int i=1;i<=n;i++)
        d[i]=INF,v[i]=0;
    int cnt=0;
    q[cnt++]=1;
    v[1]=1;
    d[1]=0;
    while(cnt>0)
    {
        int c=q[--cnt];
        v[c]=0;
        for(int i=1;i<=n;i++)
        {
            if(mp[c][i]!=-1&&d[i]>d[c]+mp[c][i])
            {
                d[i]=d[c]+mp[c][i];
                if(!v[i])   v[i]=1,q[cnt++]=i;
            }
        }
    }
    return d[t];
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&(n||m))
    {
        memset(mp,-1,sizeof(mp));
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            mp[a][b]=mp[b][a]=c;
        }
        cout<<spfa(1,n)<<endl;
    }
}

-----------
//----bellman---
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int dis[121212];
int u[121212];
int v[121212];
int w[121212];
int main()
{
    int n,m;
    int check;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0||m==0)break;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
        }
        for(int i=1;i<=n;i++)
        {
            dis[i]=0x1f1f1f1f;
        }
        dis[1]=0;
        for(int k=1;k<=n-1;k++)
        {
            check=0;
            for(int i=1;i<=m;i++)
            {
                if(dis[v[i]]>dis[u[i]]+w[i])
                {
                    dis[v[i]]=dis[u[i]]+w[i];
                    check=1;
                }
                if(dis[u[i]]>dis[v[i]]+w[i])
                {
                    dis[u[i]]=dis[v[i]]+w[i];
                    check=1;
                }
            }
            if(check==0)break;
        }
        printf("%d\n",dis[n]);
    }
}
