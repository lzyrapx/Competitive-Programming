#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int ans=0;
const int maxn = 1001;
char map[maxn][maxn];
int visited[maxn][maxn];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct node
{
    int x,y;
    int time;
    friend bool operator < (node a,node b)
    {
        return a.time>b.time;
    }
};
int n,m;
int check(int x,int y)
{
    if(0<=x&&x<n&&0<=y&&y<m&&map[x][y]!='#')
      return 1;
      else return 0;

}
int  bfs(int x,int y)
{
    priority_queue<node>q;  //优先队列 
  // queue<node>q;
    memset(visited,0,sizeof(visited));
    node st,ed;
    st.x=x;
    st.y=y;
    st.time=0;
    visited[st.x][st.y]=1;
    q.push(st);
    while(!q.empty())
    {
    	st=q.top(); 
       // st=q.front();  
         q.pop();
        if(map[st.x][st.y]=='a')
        {
        	  return st.time;
		 }     
       
        for(int i=0;i<4;i++)
        {
            ed.x=st.x+dir[i][0];
            ed.y=st.y+dir[i][1];
            if(check(ed.x,ed.y)&&!visited[ed.x][ed.y])
            {
                if(map[ed.x][ed.y]=='x')
                    ed.time=st.time+2;
                else
                    ed.time=st.time+1;
                visited[ed.x][ed.y]=1;
                q.push(ed);
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        int x,y;
       // memset(map,'\0',sizeof(map));
        for(i=0;i<n;i++)
        {
              for(j=0;j<m;j++)
             {
             	
				 cin>>map[i][j];
                if(map[i][j]=='r')  
                {
                    x=i;
                    y=j;
                }
            }
        }
       ans=bfs(x,y);
        if(ans==-1)
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        else
            printf("%d\n",ans);

    }
    return 0;
}
