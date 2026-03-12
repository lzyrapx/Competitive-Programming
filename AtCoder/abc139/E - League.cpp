#include <bits/stdc++.h>

using namespace std;

const int maxn = 1234;
vector<int> edge[maxn * maxn], tmp[maxn * maxn];

/*
 2 -> 3 <- 1
 ^         | 
 |         |
  _ _ _ _ _

 2 -> 3    1
 ^         |  
 |         |
  _ _ _ _ _

topoSort to check cycle + longest path on the path, O(n^2)
*/
int color[maxn * maxn];
int dp[maxn * maxn];

bool dfs1(int u)
{
    if (color[u] == 2)
        return true;
    color[u] = 1; // visited
    for (auto v : edge[u])
    {
        if (color[v] > 0)
        {
            if (color[v] == 1)
                return false; // cycle
        }
        if (!dfs1(v))
        {
            return false;
        }
    }
    color[u] = 2;
    return true;
}

int dfs2(int u)
{
    if (dp[u])
    {
        return dp[u];
    }
    int cnt = 0;
    for (auto v : edge[u])
    {
        cnt = max(cnt, dfs2(v));
    }
    dp[u] = cnt + 1;
    return dp[u];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            int a;
            cin >> a;
            tmp[i].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            int r1 = i, c1 = tmp[i][j - 1];
            int r2 = i, c2 = tmp[i][j];
            if (r1 > c1)
                swap(r1, c1);
            if (r2 > c2)
                swap(r2, c2);
            int s = r1 * n + c1;
            int t = r2 * n + c2;
            edge[s].push_back(t);
        }
    }
    for (int i = 0; i < n * n; i++)
    {
        if (color[i] == 0 && !dfs1(i))
        {
            cout << "-1" << endl;
            exit(0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n * n; i++)
    {
        ans = max(ans, dfs2(i));
    }
    cout << ans << endl;
    return 0;
}