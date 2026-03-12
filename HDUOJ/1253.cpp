#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int p,time;
int map[110][110][110];
int mark[110][110][110];
int dir[6][3]={{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,-1,0},{0,1,0}};
struct node
{
	int x,y,z,step;
	/*
	friend bool operator< (node a, node b)
	{
		return a.step>b.step;
	}
	*/
};
void bfs(int x,int y,int z)
{
	node st,ed;
  //	priority_queue<node>q;
  queue<node>q;
	st.x=x;
	st.y=y;
	st.z=z;
	mark[0][0][0]=1;
	st.step=0;
	q.push(st);
	while(!q.empty())
	{
		ed=q.front();
		//ed=q.top();
		q.pop();
		if(ed.x==n-1&&ed.y==m-1&&ed.z==p-1)
        {
            if(ed.step<=time)
            {
                printf("%d\n",ed.step);
                return ;
            }
        }
         for(int k=0;k<6;k++)
        {
            st.x=ed.x+dir[k][0];
            st.y=ed.y+dir[k][1];
            st.z=ed.z+dir[k][2];
            if(st.x>=0&&st.x <n&&st.y>=0&&st.y<m&&st.z>=0&&st.z<p&&map[st.x][st.y][st.z]!=1&&!mark[st.x][st.y][st.z])
            {
                st.step=ed.step+1;
                mark[st.x][st.y][st.z]=1;//²»ÔÙËÑË÷
                q.push(st); 
            }
        }
    }
    printf("-1\n");

}
int main()
{
	int t,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&p,&time);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                for(k=0;k<p;k++)
                {
                    scanf("%d",&map[i][j][k]);
                    mark[i][j][k]=0;
                }
            }
        }
        bfs(0,0,0);
    }
	return 0;
}