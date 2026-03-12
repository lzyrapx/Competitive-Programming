#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf 0x6fffff
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int map[10][10];
int vis[10][10];
int n,m,x2,y2;
struct node
{
	int x,y;
	int time,step;
};
void bfs(int x,int y)
{
	int i;
	node st,ed;
	queue<node>q;
	st.x=x;
	st.y=y;
	st.time=6; //炸弹倒时器
	q.push(st);
	while(!q.empty()) 
	{
		st=q.front();
		q.pop();
		if(st.x==x2&&st.y==y2)
		{
			printf("%d\n",st.step);
			return ;
		}
		for(i=0;i<4;i++)
		{
			ed.x=st.x+dir[i][0];
			ed.y=st.y+dir[i][1];
			ed.time=st.time-1; //倒时：减一 
			ed.step=st.step+1; //步数：加一
			if(ed.x>=0 && ed.y>=0 && ed.x<n && ed.y<m && map[ed.x][ed.y]!=0 && ed.time>0 && vis[ed.x][ed.y]<st.time)
		    {
		    	if(map[ed.x][ed.y]==4) //重置炸弹倒时器 
		    	{
		    		ed.time=6; 
				}
				vis[ed.x][ed.y]=ed.time;
				q.push(ed);
				
			}
		}
		
	}
	printf("-1\n");
}
int main()
{
	int t,i,j;
	int x1,y1;
	cin>>t;
	while(t--)
	{
		int i,k;
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>map[i][j];
				if(map[i][j]==2)
				{
					x1=i;
					y1=j;
				}
				if(map[i][j]==3)
				{
					x2=i;
					y2=j;
				}
			}
			
		}
		memset(vis,0,sizeof(vis));
			bfs(x1,y1);
	}
	return 0;
}
