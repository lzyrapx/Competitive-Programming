/*
* this code is made by LzyRapx
* Problem: 1100
* Verdict: Accepted
* Submission Date: 2017-06-21 09:57:55
* Time: 36MS
* Memory: 1932KB
*/

//http://blog.csdn.net/liangzhaoyang1/article/details/73527783

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+10;
const int N = 110;
const int M = 10000;
const int mod = 1e9 + 7;
const int inf = ~0U >> 2;
  
struct Node
{
    int to, next, w;
}e[M << 1];
int head[N], size;
int n, m, T;
int x[N], w[N], t[N];
  
int dis[N];
bool flag[N];
  
void addedge(int from, int to, int w)
{
    e[size].to = to;
    e[size].w = w;
    e[size].next = head[from];
    head[from] = size++;
}
void spfa()
{
    queue<int> q;
    fill(dis, dis + n + 1, inf);
    memset(flag, false, sizeof(flag));
    dis[0] = 0;
    q.push(0);
    while(!q.empty())
    {
        int x = q.front(); 
        q.pop();
        flag[x] = false;
        for(int i = head[x]; ~i; i = e[i].next)
        {
            int to = e[i].to;
            if(dis[to] - dis[x] > e[i].w)
            {
                dis[to] = dis[x] + e[i].w;
                if(!flag[to])
                {
                    flag[to] = true;
                    q.push(to);
                }
            }
        }
    }
}
  
ll dp[2][1010];
int s;
  
void DP()
{
    memset(dp, -1, sizeof(dp));
    dp[s][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        s ^= 1;
        for(int j = 0; j <= T; j++) dp[s][j] = dp[s ^ 1][j];
          
        int cur_t = dis[i], cur_w = 0;
        for(int k = 1; k <= x[i]; k++)
        {
            cur_t += t[i];
            cur_w += w[i];
            for(int j = T; j >= cur_t; --j)
            {
                if(dp[s ^ 1][j - cur_t] != -1)
                {
                    dp[s][j] = max(dp[s][j], dp[s ^ 1][j - cur_t] + cur_w);
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= T; i++){
        ans = max(ans, dp[s][i]);   
    }
    cout<<ans<<endl;
}
int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &n, &m, &T);
    for(int i = 1; i <= n; ++i) 
    	scanf("%d%d%d", &x[i], &w[i], &t[i]);
     
    for(int i = 0;i < m; i++)
    {
        int x,y,w;
        scanf("%d%d%d", &x, &y, &w);
        addedge(x, y, w);
    }
    spfa();
    DP();
    return 0;
}