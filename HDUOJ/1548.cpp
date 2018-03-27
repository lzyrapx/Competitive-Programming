#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int flag[250],floor[250],N,A,B;
struct node
{
    int step;
    int num;
};

int bfs(int A,int B)
{
	
    int up,down;
    node temp,st;
    st.step=A;
    st.num=0;
    flag[A]=1;
    
    queue<node>q;
    q.push(st);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp.step == B) 
		{
			return temp.num;
		}
        up = temp.step+floor[temp.step];
        down=temp.step-floor[temp.step];
        if(!flag[up] && up<=N)
        {
            flag[up]=1;
            st.step=up;
            st.num=temp.num+1; //计数 
            q.push(st);
        }
        if(!flag[down] && down>0) 
        {
            flag[down]=1;
            st.step=down;
            st.num=temp.num+1;  //计数 
            q.push(st);
        }
    }
    return -1;
}


int main()
{
    while(cin>>N && N)
    {
        memset(flag,0,sizeof(flag));
        scanf("%d%d",&A,&B);
        for(int i=1; i<=N; i++)
        {
            scanf("%d",&floor[i]);
        }
        printf("%d\n",bfs(A,B));
    }
    return 0;
}