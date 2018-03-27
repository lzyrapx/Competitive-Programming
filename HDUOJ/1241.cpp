#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
char map[110][110];
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
int vis[110][110];
int next_x,next_y;
void dfs(int x,int y)
{
	map[x][y]='*'; //标志一下，避免重复计数 
	for(int k=0;k<8;k++)
	{
		next_x=x+dir[k][0];
		next_y=y+dir[k][1];
		if(map[next_x][next_y]=='@')
		{
			dfs(next_x,next_y);
		}
	}
}
int main()
{
	int n,m;
	while(cin>>n>>m,m&&n)
	{
		int count=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>map[i][j];
			}
			
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(map[i][j]=='@')
				{
					count++;
					dfs(i,j);
				}
			}
			
		}
		printf("%d\n",count);
	}
	return 0;
}
--------------------------------

#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
char a[100][100];
int sum;
int dir[8][2]={1,0,1,1,1,-1,0,1,0,-1,-1,0,-1,1,-1,-1};      //8个方向
struct node
{
    int x;
    int y;
};
int OK(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return true;
    return false;
}
void bfs(int x,int y)
{
    int i;
    node now,next;
    queue<node> q;
    now.x=x;
    now.y=y;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(i=0;i<8;i++)
        {
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            if(OK(next.x,next.y)&&a[next.x][next.y]=='@')     //是油田哦
            {
                a[next.x][next.y]='*';     //油田群遍历，标记
                q.push(next);
            }
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)&&m)
    {
        sum=0;
        for(i=0;i<n;i++)
            scanf("%s",a[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]=='@')      //找到油田
                {
                    sum++;
                    bfs(i,j);
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
