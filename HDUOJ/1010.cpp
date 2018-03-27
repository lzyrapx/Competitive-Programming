#include<iostream>       
#include<cstdlib>      
#include<cstdio>      
#include<cmath>      
#include<cstring>      
#include<string>      
#include<cstdlib>      
#include<iomanip>      
#include<vector>      
#include<list>      
#include<map>      
#include<queue>    
#include<algorithm>      
using namespace std;
int n,m,ex,ey,t;
bool success;
char maze[10][10]; 
/*
 stx ---->开始x坐标
 sty ---->开始y坐标
 dt  ---->花掉时间
*/
void dfs(int stx,int sty,int dt )
{
 
    if(stx<=0||stx>n||sty<=0||sty>m)     
	               return ;
	if(stx==ex&&sty==ey&&dt==t)
	        success=true;
	if(success) return ;
   int temp=(t-dt)-abs(ex-stx)-abs(ey-sty);
	if(temp<0||temp&1)   //奇偶剪枝
		return ;
		
/*
   0 1 0 1 0 1 0 1 0
   1 0 1 0 1 0 1 0 1
   0 1 0 1 0 1 0 1 0
   1 0 1 0 1 0 1 0 1
   0 1 0 1 0 1 0 1 0
   1 0 1 0 1 0 1 0 1
   0 1 0 1 0 1 0 1 0
   1 0 1 0 1 0 1 0 1 
 无论是从o 开始还是从1开始，
 都是 0--->1 或者1--->0 都是奇数步
  0-->0 , 1--->1 都是偶数步
*/
   //对上下左右的搜索
   if(maze[stx][sty+1]!='X')   //向右搜索
   {
	   maze[stx][sty+1]='X'; 
	   dfs(stx,sty+1,dt+1);
	   maze[stx][sty+1]='.';
   }
   
   if(maze[stx+1][sty]!='X')   //向下搜索
    {
	    maze[stx+1][sty]='X';  
	   dfs(stx+1,sty,dt+1);
	    maze[stx+1][sty]='.';
    }
   if(maze[stx][sty-1]!='X')   //向左搜索
   {
	    maze[stx][sty-1]='X';  
	   dfs(stx,sty-1,dt+1);
	    maze[stx][sty-1]='.';
   }
  if(maze[stx-1][sty]!='X')   //向上搜索
   {
	    maze[stx-1][sty]='X';  
	    dfs(stx-1,sty,dt+1);
	    maze[stx-1][sty]='.';
   }
  return ;
}

int main()
{
	int stx,sty,wall;
  while(scanf("%d%d%d",&n,&m,&t),n+m+t)
  {
	  getchar();
	  wall=0;    //统计障碍物的个数
   for(int i=1;i<=n;i++)
   {
	   for(int j=1;j<=m;j++)
	   {
		   scanf("%c",&maze[i][j]);
		   if(maze[i][j]=='S')
		   {
			   stx=i;     // 标注开始的x轴的位置
			   sty=j;     // 标注开始的y轴的位置
		   }
		   else
			if(maze[i][j]=='D')
			{
               ex=i;    // 标注结束的x轴的位置
			   ey=j;    // 标注结束的y轴的位置
			}
			else if(maze[i][j]=='X')
			{
               wall++;
			}
	   }
	   getchar();
   }
    success=false;
    maze[stx][sty]='X'; //堵住入口
    if( n*m-wall<=t )  //因为只有在t时刻door才打开
        printf("NO\n");
    else 
	{
		dfs(stx,sty,0);
		if(success)
			printf("YES\n");
		else
			printf("NO\n");
	}
  }
  return 0;
}
 

