#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int step;  
int dir[8][2]={{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int map[10][10],ex,ey;  
char s1[5],s2[5];  
struct node  
{  
    int x,y,step;
//	friend bool operator <(node a,node b)
//	{
//		return a.step>a.step;
//	  }  
};  

int bfs()  
{  
    int i;  
    memset(map,0,sizeof(map));  
    node st,ed;  
    st.x = s1[0]-'a';  
    st.y = s1[1]-'1';  
    st.step = 0;  
    ex = s2[0]-'a' ; 
    ey = s2[1]-'1';  
   // priority_queue<node> q;  
    queue<node> q;
    map[st.x][st.y] = 1;  
    q.push(st);  
    
    while(!q.empty())  
    {  
        st = q.front();  
        //st=q.top();
        q.pop();  
        if(st.x == ex && st.y == ey)
		{
			 return st.step;  
		  }     
        for(i = 0; i<8; i++)  
        {  
            ed.x = st.x+dir[i][0];  
            ed.y = st.y+dir[i][1];       
            if (ed.x>=0&&ed.x<8&&ed.y>=0&&ed.y<8&&map[ed.x][ed.y]==0)  
            {  
                ed.step=st.step+1;  
                map[ed.x][ed.y]=1;  
                q.push(ed);  
            }  
        }  
    }  
    return 0;  
}  
  
int main()  
{  
    while(~scanf("%s%s",s1,s2))  
    {  
        printf("To get from %s to %s takes %d knight moves.\n",s1,s2,bfs());  
    }  
    return 0;  
}  