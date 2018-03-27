#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
int k;int n,m;
char map[1110][1110];
char mark[1110][1110];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node
{
	int x,y;
	int times;
	int dir;
};
int bfs(node s,node e)
{
	s.times =0;
	s.dir=-1;
	queue<node>q;
	mark[s.y][s.x]=0;
	q.push(s);
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(t.x==e.x&&t.y==e.y&&t.times<=k)
		{
				return 1;		
		}	
        for(int i = 0 ; i < 4 ; ++i)
        {
            node temp;
            temp.x = t.x + dir[i][0];
            temp.y = t.y + dir[i][1];
            temp.dir = i;
            if(t.dir == -1)
            temp.times = 0;
            else if(temp.dir == t.dir)
            temp.times = t.times;
            else
            temp.times = t.times + 1;
            if(temp.x >= 1 && temp.y >= 1 && temp.x <= n && temp.y <= m && temp.times <=k && temp.times <= mark[temp.y][temp.x])
            {
                if(temp.x == e.x && temp.y == e.y)
                return 1;
                if(map[temp.y][temp.x]=='.')
                {
                    mark[temp.y][temp.x] = temp.times;
                    q.push(temp);
                }
            }
        }		
	}
	return 0;
}
int main()
{
	int t;

	int x1,x2,y1,y2;
	scanf("%d",&t);
	while(t--)
	{
			int flag=0;
		scanf("%d %d",&m,&n);
		for(int i=1;i<=m;i++)
		{
			getchar();  //×¢Òâ£¬WAÁË2´Î 
			for(int j=1;j<=n;j++)
			{
				scanf("%c",&map[i][j]);
				mark[i][j]=110;
			}
		}
      //	getchar();
	    node s,e;
		scanf("%d %d %d %d %d",&k,&s.x,&s.y,&e.x,&e.y);
		
		if(bfs(s,e)) printf("yes\n");
		else printf("no\n");
	
	}
	return 0;
}