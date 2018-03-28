#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>
#include <queue>
 
using namespace std;
  
typedef long long ll;
typedef pair<int, int> pii;
 
const int N = 3010;
 
int n, m;
int f[N], d[N], a[N], b[N];
int id[N], cnt;
vector<int> e[N];
 
void dfs(int x, int fa, int dep){
    f[x] = fa;
    d[x] = dep;
    for(int i = 0; i < e[x].size(); ++i)
        if(e[x][i] != fa) dfs(e[x][i], x, dep + 1);
}
void find(int x, int y, int z){
    cnt = 0;
    if(d[y] < d[z]) swap(y, z);
    while(d[y] != d[z]){
        id[cnt++] = y;
        y = f[y];
    }
    while(y != z){
        id[cnt++] = y;
        id[cnt++] = z;
        y = f[y], z = f[z];
    }
    while(y != x){
        id[cnt++] = y;
        y = f[y];
    }
    id[cnt++] = x;
}
 
int dp[100];
 
int DP(int w){
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < cnt; ++i){
        int x = id[i];
        for(int j = w; j >= a[x]; --j)
            if(dp[j - a[x]] != -1) dp[j] = max(dp[j], dp[j - a[x]] + b[x]);
    }
    int ret = 0;
    for(int i = 0; i <= w; ++i)
        ret = max(ret, dp[i]);
    return ret;
}
int main(){ 
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d %d", a + i, b + i);
    for(int i = 0, x, y; i < n - 1; ++i){
        scanf("%d %d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, -1, 0);
    for(int i = 0, x, y, z, w; i < m; ++i){
        scanf("%d %d %d %d", &x, &y, &z, &w);
        find(x, y, z);
        printf("%d\n", DP(w));
    }
    return 0;
}