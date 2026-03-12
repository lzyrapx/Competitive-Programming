#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<algorithm>
using namespace std;
#include<map>
#include<iostream>
#define INF 0x3f3f3f3f
typedef struct
{
    int pos;
    int next;
} node;
node q[200010];
int flag[100010];
int du[100010];
priority_queue<int> que;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(flag,0,sizeof(flag));
        memset(du,0,sizeof(du));
        int count=1;
        for(int i=1; i<=m; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            q[count].pos=y;
            q[count++].next=flag[x];
            flag[x]=count-1;
            du[y]++;

        }
        for(int i=1; i<=n; i++)
        {
            if(du[i]==0)
                que.push(i);
        }
        int now=INF;
        long long  sum=0;
        while(!que.empty())
        {
            int x=que.top();

            que.pop();
            for (int i=flag[x]; i!=0; i=q[i].next)
            {
                du[q[i].pos]--;
                if(du[q[i].pos]==0)
                    que.push(q[i].pos);
            }
              if(x<now)
                now=x;
            sum+=now;

        }
        printf("%I64d\n",sum);
    }
}