#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
struct graph
{
    char point;
    int step;
}G[maxn][maxn];
int vis[maxn][maxn];
int n, m, k;
void gao()
{
    vis[1][k] = 1;
    G[1][k].step = 1;
    int x = 1, y = k;
    int nx, ny;
    while(1)
    {
        if(G[x][y].point == 'E')
        {
            nx = x; ny = y + 1;
        }
        else if(G[x][y].point == 'S')
        {
            nx = x + 1; ny = y;
        }
        else if(G[x][y].point == 'W')
        {
            nx = x; ny = y - 1;
        }
        else
        {
            nx = x - 1; ny = y;
        }
        if(nx<1 || nx>n || ny<1 || ny>m)
        {
            cout << G[x][y].step << " step(s) to exit\n";
            return ;
        }
        else
        {
            if(!vis[nx][ny])
            {
                vis[nx][ny] = 1;
                G[nx][ny].step = G[x][y].step + 1;
                x = nx; y = ny;
            }
            else
            {
                cout << G[nx][ny].step-1 << " step(s) before a loop of "
                << G[x][y].step-G[nx][ny].step+1 << " step(s)\n";
                return ;
            }
        }
    }
}
int main()
{
	ios::sync_with_stdio(0);
    while(cin >> n >> m >> k)
    {
    	if(n==0&&m==0&&k==0)break;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                cin >> G[i][j].point;
                G[i][j].step = 0;
            }
        memset(vis, 0, sizeof(vis));
        gao();
    }
    return 0;
}