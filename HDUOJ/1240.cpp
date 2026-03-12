
#include<stdio.h>
#include<queue>
using namespace std;
char map[10][10][10];
int startx,starty,startz,endx,endy,endz;
int n;
struct node
{
    int x,y,z,step;
    friend bool operator <(node a,node b)
    {
        return a.step>b.step;
    }
};
void bfs(int x1,int y1,int z1,int x2,int y2,int z2)
{
    int k;
    int move[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
    node now,next;
    priority_queue<node>q;
    now.x=x1;
    now.y=y1;
    now.z=z1;
    now.step=0;
    map[now.x][now.y][now.z]='X';
    q.push(now);
    while(!q.empty())
    {
        next=q.top();
        q.pop();
        if(next.x==x2&&next.y==y2&&next.z==z2)
        {
            printf("%d %d\n",n,next.step);
            return ;
        }
        for(k=0;k<6;k++)
        {
            now.x=next.x+move[k][0];
            now.y=next.y+move[k][1];
            now.z=next.z+move[k][2];
            if(now.x>=0&&now.x<n&&now.y>=0&&now.y<n&&now.z>=0&&now.z<n&&map[now.x][now.y][now.z]=='O')
            {
                now.step=next.step+1;
                map[now.x][now.y][now.z]='X';
                q.push(now);
            }
        }
    }
    printf("NO ROUTE\n");
}
int main()
{
    int i,j,k;
    char s[10];
    while(scanf("%s %d",s,&n)!=EOF)
    {
        getchar();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    scanf("%c",&map[i][j][k]);
                }
                getchar();
            }
            getchar();
        }
        scanf("%d%d%d%d%d%d",&startx,&starty,&startz,&endx,&endy,&endz);
        scanf("%s",s);
        bfs(startx,starty,startz,endx,endy,endz);
    }
    return 0;
}

-----------------------
#include<iostream>
#include<cstring>
#include<queue>
#include<stdio.h>
#define max 11
using namespace std;
char map[max][max][max];
int vis[max][max][max];
int n;
int st1,st2,st3,en1,en2,en3;
int step;
struct Q
{

    int x,y,z;
    int step;
};
void bfs()
{
    step=0;
    memset(vis,0,sizeof(vis));
    queue<Q> q;
    Q temp,now;
    
    temp.x=st1;
	temp.y=st2;
	temp.z=st3;
	temp.step=0;
    vis[temp.x][temp.y][temp.z]=1;
    q.push(temp);
    int i,j,k;
    int x[6]={ 1,-1, 0, 0,  0, 0};
    int y[6]={ 0, 0, 1, -1, 0, 0};
    int z[6]={ 0, 0, 0, 0,  1, -1};
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        int a,b,c;
        for(i=0;i<6;i++)
        {
            a=now.x+x[i];
			b=now.y+y[i];
			c=now.z+z[i];
            if(a==en1&&b==en2&&c==en3)
            {
                step=now.step+1;
                return;
            }
            if(a>=0&&b>=0&&c>=0&&a<n&&b<n&&c<n&&vis[a][b][c]==0&&map[a][b][c]=='O')
            {
                vis[a][b][c]=1;
                temp.x=a;
			    temp.y=b;
				temp.z=c;
				temp.step=now.step+1;
                q.push(temp);
            }
        }
        
        
    }
    
}
int main()
{
    int i,j;
    char s[10];
    while(scanf("%s%d",s,&n)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++)
        {

            for(j=0;j<n;j++)
            {

                getchar();
                scanf("%s",map[i][j]);
            }
        }
        scanf("%d%d%d%d%d%d",&st1,&st2,&st3,&en1,&en2,&en3);
         getchar();
       	scanf("%s",s); 
       	if(st1==en1&&st2==en2&&st3==en3)
       	{
			printf("%d %d\n",n,0);
       		continue;
       	}
       	bfs();
       	if(step)
       	{
       		printf("%d %d\n",n,step);
       	}
       	else{
       		printf("NO ROUTE\n");
       }
    }
    return 0;
}
