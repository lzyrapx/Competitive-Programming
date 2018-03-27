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
#define INF 100000000
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int n,m;
int flag;
int Count;
char map[200][200];
int mark[200][200];
struct node
{
   int x,y,step;     
}st,ed;
void bfs()
{
	
  queue<node>q;
  
  q.push(st);
  node v,vn;
  int min=INF;
  mark[st.x][st.y]=1;    
  while(!q.empty())
   {
     vn=q.front();
     q.pop();
     if(vn.x==ed.x&&ed.y==vn.y) 
       {
         if(min>vn.step) min=vn.step;  //到达目标点 
       }
     for(int i=0;i<4;i++)
       {
         flag=0;
         Count=0;
        
         v.x=vn.x+dx[i];
         v.y=vn.y+dy[i];
         v.step=vn.step+1;
         
         if(map[v.x][v.y]=='|'||map[v.x][v.y]=='-') //到达楼梯
           {
            
			 int k=i+vn.step%2;
             if(k==4)  k=0;
             flag=1;
             if(((k==1)||(k==3))&&map[v.x][v.y]=='-')   //当楼梯是“—” 时 ，并且可以到达对面 
               {    
                     v.x=v.x+dx[i];
                     v.y=v.y+dy[i];
               }
             else if(((k==0)||(k==2))&&map[v.x][v.y]=='|') //当楼梯是“|” 时 ，并且可以到达对面
               {
                     v.x=v.x+dx[i];
                     v.y=v.y+dy[i];    
               }
             else {           //不是楼梯时，正常走 
                     Count=1;
                     v.x=v.x+dx[i];
                     v.y=v.y+dy[i];
                     v.step=v.step+1;
                  }
             
    
           }
         if(v.x<0||v.y<0||v.x>=n||v.y>=m)  continue; //越界 
         else if(map[v.x][v.y]=='*') continue;       //遇到阻碍物 
        else if(mark[v.x][v.y]<=v.step) {continue;}   //走过的路 

         if(flag&&Count==0)  mark[v.x-2*dx[i]][v.y-2*dy[i]]=v.step-1; 
         else if(flag&&Count)  mark[v.x-2*dx[i]][v.y-2*dy[i]]=v.step-2; 
         mark[v.x][v.y]=v.step;
		 q.push(v);
       }    
   }
  printf("%d\n",min);
}

int main()
{
	while(cin>>n>>m&&n&&m)
	{
		for(int i=0;i<100;i++)
          for(int j=0;j<100;j++)
            mark[i][j]=1000000;
             getchar();
           
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S')
				{
					st.x=i; st.y=j;
				}
				if(map[i][j]=='T')
				{
					ed.x=i ; ed.y =j;
				}
			}
			getchar(); //这里没加getchar，结果WA了几发 
		}
		st.step=0;
		bfs();
	}
	return 0;
}