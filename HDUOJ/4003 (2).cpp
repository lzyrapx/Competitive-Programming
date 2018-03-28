//AC
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int now,next,val;
}tree[20005];

int dp[10005][15];
int head[10005];
int n,s,k,len;

void addedge(int x,int y,int w)
{
    tree[len].now = y;
    tree[len].val = w;
    tree[len].next = head[x];
    head[x] = len++;
}

void dfs(int root,int fa)
{
    
    for(int i = head[root];i!=-1;i = tree[i].next)
    {
        int son = tree[i].now;
        if(son == fa)  continue;
        dfs(son,root);
        for(int j = k; j>=0;j--)
        {
            //先将dp[son][0]放进树中，因为dp[son][0]是表示用一个机器人去走完所有子树，最后又回到 pos这个节点，所以花费要乘以2
            dp[root][j]+=dp[son][0]+2*tree[i].val;
            for(int l = 1;l<=j;l++)//再找到更优的,就是分组背包 
            dp[root][j] = min(dp[root][j],dp[root][j-l]+dp[son][l]+l*tree[i].val);
        }
    }
}

int main()
{
    int i,x,y,w;
    while(~scanf("%d%d%d",&n,&s,&k))
    {
        len = 0;
        memset(head,-1,sizeof(head));
        memset(dp,0,sizeof(dp));
        for(i = 1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            addedge(x,y,w);
            addedge(y,x,w);
        }
        dfs(s,0);
        printf("%d\n",dp[s][k]);
    }
    return 0;
}

//TLE
/*
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> V[20010];
//dp[i][j]表示对于以i结点为根结点的子树，放j个机器人所需要的权值和。 
int dp[20010][30];
int val[20010];
int n,s,k;
void dfs(int root,int fa)
{
    
    for(int i=0; i< V[root].size();i++)
    {
        int son=V[root][i];
        if(son==fa)continue;
        dfs(son,root);
        for(int j=k;j>=0;--j)
        {
            //先将dp[son][0]放进树中，因为dp[son][0]是表示用一个机器人去走完所有子树，最后又回到 pos这个节点，所以花费要乘以2 
            dp[root][j]+=dp[son][0]+ 2*val[i];
            //再找到更优的
            for(int l=1;l<=j;l++) 
            {
                dp[root][j] = min(dp[root][j],dp[root][j-l]+dp[son][l]+l*val[i]);
            }
        }
    }
}

int main()
{
    int x,y;
    while(~scanf("%d%d%d",&n,&s,&k))
    {
        for(int i=0;i<n;i++) V[i].clear();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&x,&y,&val[i]);
            V[x].push_back(y);
            V[y].push_back(x);
        }
        dfs(1,0);
        printf("%d\n",dp[s][k]);
    }
    return 0;
}
*/
