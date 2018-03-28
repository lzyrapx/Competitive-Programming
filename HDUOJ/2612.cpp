#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define N 210
int n, m;
char map[N][N];
int vis[N][N], dis[N][N][2], flag;
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
struct node
{
    int x;
	int y;
	int  step;
};

bool check(int next_x,int next_y)
{
	if(next_x>=0&&next_x<n&&next_y>=0&&next_y<m&&!vis[next_x][next_y])
	return true;
	else return false;
}
void bfs(int x, int y)
{
    node head, next;
    head.x=x;
    head.y=y;
    head.step=0;
    vis[x][y]=1;
    queue <node> q;
    q.push(head);

    while(!q.empty())
    {
        head=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            next.x=head.x+dir[i][0];
            next.y=head.y+dir[i][1];
            if(check(next.x,next.y)&&(map[next.x][next.y]=='.'||map[next.x][next.y]=='@'))
            {
                vis[next.x][next.y]=1;
                next.step=head.step+1;
                
                if(map[next.x][next.y]=='@')             
                    dis[next.x][next.y][flag]=min(dis[next.x][next.y][flag], next.step);
                q.push(next);
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        memset(dis, INF, sizeof(dis));
        for(int i=0; i<n; i++)
            scanf("%s", map[i]);

        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(map[i][j]=='Y')
            {
                flag=0;
                memset(vis, 0, sizeof(vis));
                bfs(i, j);
            }
            else if(map[i][j]=='M')
            {
                flag=1;
                memset(vis, 0, sizeof(vis));
                bfs(i, j);
            }
        }

        int ans=INF;

        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(map[i][j]=='@'&&ans>dis[i][j][0]+dis[i][j][1])
                ans=dis[i][j][0]+dis[i][j][1];
        }
        printf("%d\n", ans*11);
    }
}