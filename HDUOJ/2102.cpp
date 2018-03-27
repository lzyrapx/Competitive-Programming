
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int vis[2][11][11];
char map[2][11][11];
int n,m,times,flag;

int check(int next_x,int next_y)
{
	if(next_x>=0&&next_x<n&&next_y>=0&&next_y<m)
	return 1;
	else return 0;
}


int dfs(int x,int y,int z,int t)
{
	if(map[z][x][y]=='P')
	{
		if(t<=times)
		return 1;
		else return 0;
	}
	
	for(int i=0; i<4; i++)
	{
		int next_x=x+dx[i];
		int next_y=y+dy[i];
		if(check(next_x,next_y)&&!vis[1-z][next_x][next_y]&&map[z][next_x][next_y]=='#'&&map[1-z][next_x][next_y]!='*'&&map[1-z][next_x][next_y]!='#')
		{
			vis[1-z][next_x][next_y]=1;
			if(dfs(next_x,next_y, 1-z ,t+1))  
			return 1;
			vis[1-z][next_x][next_y]=0;
		}
		else 
		 if(check(next_x,next_y)&&!vis[z][next_x][next_y]&&map[z][next_x][next_y]!='#'&&map[z][next_x][next_y]!='*')
		 {
		 	vis[z][next_x][next_y]=1;
		 	if(dfs(next_x,next_y, z ,t+1))
		 	  return 1;
		 	vis[z][next_x][next_y]=0;
		 }
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&times);
		memset(vis,0,sizeof(vis));
		memset(map,0,sizeof(map));
		for(int i=0;i<2;i++)
		{
			getchar();
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<m;k++)
				
					scanf("%c",&map[i][j][k]);//注意输入有一行间隔的。。。WA了几发。。。智障 
					getchar();
				
			}
		}
		vis[0][0][0]=1;
		if(dfs(0,0,0,0))
		{
			printf("YES\n");
		}
		else puts("NO");
	}
	return 0;
}