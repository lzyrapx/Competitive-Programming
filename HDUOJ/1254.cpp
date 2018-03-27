#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

struct node
{
    int x,y,step;
    int peox,peoy;
}a,b;

struct Node
{
    int x,y;
}p,q;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int map[10][10],n,m;
int mark[10][10][10][10];    
int judge_bfs(int starx,int stary,int endx,int endy,int tx,int ty) //判断人能否到达
{
    p.x=starx;
    p.y=stary;
    int leap[10][10];
    memset(leap,0,sizeof(leap));
    leap[p.x][p.y]=1;
    queue<Node>P;
    P.push(p);
    while(!P.empty())
    {
        q=P.front();
        P.pop();
        if(q.x==endx&&q.y==endy)
        return 1;
        for(int i=0;i<4;i++)
        {
            p.x=q.x+dir[i][0];
            p.y=q.y+dir[i][1];
            if(p.x<1||p.x>n||p.y<1||p.y>m) continue;
            if(p.x==tx&&p.y==ty) continue;
            if(leap[p.x][p.y]==0&&map[p.x][p.y]!=1)
            {
                leap[p.x][p.y]=1;
                P.push(p);
            }
        }
    }    
    return 0;
}
int bfs(int starx,int stary,int peox,int peoy) //搜箱子
{
    int i;
    a.x=starx;    
    a.y=stary;
    a.peox=peox;
    a.peoy=peoy;
    a.step=0;
    memset(mark,0,sizeof(mark));
    mark[a.x][a.y][a.peox][a.peoy]=1;
    queue<node>Q;
    Q.push(a);
    while(!Q.empty())
    {
        b=Q.front();
        Q.pop();
        if(map[b.x][b.y]==3) //终点 
        {
            return b.step;
        }
        for(i=0;i<4;i++)
        {
            a.x=b.x+dir[i][0];
            a.y=b.y+dir[i][1];
            a.step=b.step+1;
            if(a.x<1||a.x>n||a.y<1||a.y>m) continue;
            if(map[a.x][a.y]==1) continue;
            if(mark[a.x][a.y][b.x][b.y]) continue;
            if(i==0)
            {
                if(b.y-1>=1&&map[b.x][b.y-1]!=1&&judge_bfs(b.peox,b.peoy,b.x,b.y-1,b.x,b.y))
                {
                    a.peox=b.x;
                    a.peoy=b.y;
                    mark[a.x][a.y][a.peox][a.peoy]=1;
                    Q.push(a);
                }
            }
            else if(i==1)
            {
                if(b.y+1<=m&&map[b.x][b.y+1]!=1&&judge_bfs(b.peox,b.peoy,b.x,b.y+1,b.x,b.y))
                {
                    a.peox=b.x;
                    a.peoy=b.y;
                    mark[a.x][a.y][a.peox][a.peoy]=1;
                    Q.push(a);
                }
            }
            else if(i==2)
            {
                if(b.x-1>=1&&map[b.x-1][b.y]!=1&&judge_bfs(b.peox,b.peoy,b.x-1,b.y,b.x,b.y))
                {
                    a.peox=b.x;
                    a.peoy=b.y;
                    mark[a.x][a.y][a.peox][a.peoy]=1;
                    Q.push(a);
                }
            }
            else
            {
                if(b.x+1<=n&&map[b.x+1][b.y]!=1&&judge_bfs(b.peox,b.peoy,b.x+1,b.y,b.x,b.y))
                {
                    a.peox=b.x;
                    a.peoy=b.y;
                    mark[a.x][a.y][a.peox][a.peoy]=1;
                    Q.push(a);
                }
            }
        }
    }
    return 0;
}
int main()
{
    int i,j,T,starx,stary,peox,peoy;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]==2)  //箱子的起点 
            {
                starx=i;
                stary=j;
            }
            if(map[i][j]==4)  //人的位置 
            {
                peox=i;
                peoy=j;
            }
        }
        int ans=bfs(starx,stary,peox,peoy);    
        if(!ans) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}

