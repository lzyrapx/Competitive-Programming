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
int w,h;
char z[21][21];
int dfs(int i,int j){
	if(i<1||j>h||j<1||j>w)return 0;
	
	if(z[i][j]!='#')
	{
		z[i][j]='#';
		return 1+dfs(i-1,j)+dfs(i,j-1)+dfs(i+1,j)+dfs(i,j+1);  //TLE.... 
    }
	else return 0; 
}
int main()
{
	
     while(cin>>w>>h){
     	if(w==0&&h==0)break;
     	
     	for(int i=1;i<=h;i++)
     	  for(int j=1;j<=w;j++)
     	  	cin>>z[i][j];
     	  	for(int i=1;i<=h;i++){
     	  		for(int j=1;j<=w;j++)
     	  		   if(z[i][j]=='@')
     	  		   cout<<dfs(i,j)<<endl;
     	  	}
     } 
    return 0;
}


#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; //扩展的四个方向
char map[33][33];
int vis[33][33];
int n,m;
int sum;
struct node
{
	int x,y;
}
f[333];
#define inf 0xfffffff
void bfs(int x,int y)
{
	int i;
	queue<node>q;
	node st,ed;
	st.x=x;
	st.y=y;
	q.push(st);
	while(!q.empty())  //队列非空
	{
		st=q.front();
		q.pop();       
		for(i=0;i<4;i++)
		{
			ed.x=st.x+dir[i][0];
			ed.y=st.y+dir[i][1];
			if(ed.x>=n ||ed.y>=m ||ed.x<0 ||ed.y<0 ||map[ed.x][ed.y]=='#' ||map[ed.x][ed.y]=='@') //判断越界
				continue;
			map[ed.x][ed.y]='@';  //标志已经遍历过的
			sum++;
			q.push(ed);    
		}
	}
}
int main()
{
	int i,j,x,y;
	while(scanf("%d%d",&m,&n)!=EOF&&n!=0 &&m!=0)
	{
		for(i=0;i<n;i++)
			scanf("%s",map[i]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(map[i][j]=='@')  //寻找起始点
				{
					x=i;
					y=j;		 
				}
			}
			sum=1;
			bfs(x,y);
			printf("%d\n",sum);
	}
	return 0;
}
//广搜








#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char map[33][33];
int vis[33][33];
int n,m;
int sum;
#define inf 0xfffffff
void dfs(int x,int y)
{
    int sx,sy,i;
    sum++;
    for(i=0;i<4;i++)
    {
        sx=x+dir[i][0];
        sy=y+dir[i][1];
        if(sx>=n ||sy>=m ||sx<0 ||sy<0 ||map[sx][sy]=='#' ||map[sx][sy]=='@')
            continue;
          map[sx][sy]='@';
              dfs(sx,sy);
    } 
}
int main()
{
    int i,j,x,y;
    while(scanf("%d%d",&m,&n)!=EOF&&n!=0 &&m!=0)
    {
        for(i=0;i<n;i++)
            scanf("%s",map[i]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(map[i][j]=='@')
                {
                    x=i;
                    y=j;         
                }
            }
            sum=0;
            dfs(x,y);
            printf("%d\n",sum);
    }
    return 0;
}
//深搜