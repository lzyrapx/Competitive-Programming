#include<iostream>       
#include<cstdlib>      
#include<cstdio> 
#include<cstring>      
#include<cmath>           
#include<string>      
#include<cstdlib>      
#include<iomanip>      
#include<vector>      
#include<list>         
#include<queue>    
#include<algorithm>    
using namespace std;
int n,m,map[1005][1005];
int x1,x2,yy1,y2,flag; 
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int now,int step,int x,int y)
{
    if(flag==1)
        return ;
    if(step>2||step==2&&(x-x2)&&(y-y2)) //¹Ø¼ü
        return ;
    if(x==x2&&y==y2)
    {
        flag=1;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		int step1=step+1;
		
        if(now==i+1||now==0)
            step1--;
        if(dx>=1&&dx<=n&&dy>=1&&dy<=m)
        {
            if(map[dx][dy]==0)
            {
                map[dx][dy]=1;
                dfs(i+1,step1,dx,dy);
                map[dx][dy]=0;
            }
            else if(dx==x2&&dy==y2)
            {
                dfs(i+1,step1,dx,dy);
                if(flag==1)
                    return ;
            }
        }

    }
}
int main()
{
    int i,j,k;
    while(~scanf("%d%d",&n,&m)&&(m||n))
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            scanf("%d",&map[i][j]);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d%d",&x1,&yy1,&x2,&y2);
            if(map[x1][yy1]!=map[x2][y2]||map[x1][yy1]==0)
                goto a;
            flag=0;
            dfs(0,0,x1,yy1);
            if(flag)
                puts("YES");
            else
            {
                a:
                puts("NO");
            }
        }
    }
    return 0; 
}

--------------------
BFS:
#include<iostream>       
#include<cstdlib>      
#include<cstdio> 
#include<cstring>      
#include<cmath>           
#include<string>      
#include<cstdlib>      
#include<iomanip>      
#include<vector>      
#include<list>         
#include<queue>    
#include<algorithm>    
using namespace std;
int n,m;
int map[1001][1001];
int mark[1001][1001];
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
struct node{
	int i, j;
	int dir;
	int mark;
};
int bfs(int a,int b,int c,int d)
{
	int i,j;
	queue<node>q;
	node s;
	s.i=a;
	s.j=b;
	s.dir=0;
	s.mark=-1;
	mark[a][b]=-1;
	q.push(s);
	while(!q.empty())
	{
		node k=q.front();
		q.pop();
		int x,y;
		x=k.i; 
		y=k.j;
		if(k.mark>mark[x][y])
		{
			continue;
		}
		for(i=0;i<4;i++)
		{
			int dx,dy;
			dx=x+dir[i][0];
			dy=y+dir[i][1];
			if(dx>=0 && dy>=0 &&dx<n && dy<m )
			{
				if(dx==c && dy==d||map[dx][dy]==0)
				{
				   node dk;
				   dk.i=dx;
				   dk.j=dy;
				   dk.dir=i+1;
				   if(dk.dir!=k.dir)
				   {
				   	  dk.mark=k.mark+1;
				   }
				   else
				   {
				   	  dk.mark=k.mark;
				   }
				   if(dk.mark>2)
				   {
				    	continue;
				   }
				   	 if( mark[dx][dy]==-1||dk.mark<mark[dx][dy])
				   	 {
				   	 	mark[dx][dy]=dk.mark;
				   	 	q.push(dk);
				   	 	if(dx==c&&dy==d)
				   	 	{
				   	 		return 1;
							}
						}
				   
				  
				}
			}
		}
	}
	return 0;
}
int main()
{
    while(cin>>n>>m&&n&&m)
    {
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			cin>>map[i][j];
    			
			}
		}
		int k;
		cin>>k;
		for(int i=0;i<k;i++)
		{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			if(map[a-1][b-1]==0||map[c-1][d-1]==0)
			{
				printf("NO\n");
			}
			else if (map[a-1][b-1]!=map[c-1][d-1])
			{
				printf("NO\n");
			}
			else if(a==c&&b==d)
			{
				printf("NO\n");
			}
			else {
				memset(mark,-1,sizeof(mark));
				if(bfs(a-1,b-1,c-1,d-1))
				{
					printf("YES\n");
				}
				else{
						printf("NO\n");
				}
			
			}
		}
	}
	return 0;
}
