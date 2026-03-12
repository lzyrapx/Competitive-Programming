#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 8e4 + 7;

int dp[2*N][26];  // ST表，用于RMQ查询，数组开到2*N因为遍历后序列长度为2*n-1
bool vis[26];
struct edge {
    int from, to;
    int next;
} e[2*N];
int tot, head[N];
int cnt;
int num[N];

void init() {
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    memset(num, 0, sizeof(num));
    cnt = 0;
}

void addedge(int u, int v) {
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

int ver[2*N], R[2*N], first[N];
// ver:节点编号  R：深度  first：点编号位置

void dfs(int u ,int dep) {
    vis[u] = true;
    ver[++tot] = u;
    first[u] = tot;
    R[tot] = dep;
    for(int k = head[u]; k != -1; k = e[k].next) {
        if( !vis[e[k].to] ) {
            int v = e[k].to;
            dfs(v, dep+1);
            ver[++tot] = u;
            R[tot] = dep;
        }
    }
}

void ST(int n) {
    for(int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 1; i + (1<<j) - 1 <= n; i++) {
            int a = dp[i][j-1] , b = dp[i+(1<<(j-1))][j-1];
            dp[i][j] = R[a] < R[b] ? a : b;
        }
    }
}

int RMQ(int l, int r) {
    int k = 0;
    while((1 << (k + 1)) <= r - l + 1) {
        k++;
    }
    int a = dp[l][k], b = dp[r - (1<<k) + 1][k]; // 保存的是编号
    return R[a] < R[b] ? a : b;
}

int LCA(int u, int v) {
    int x = first[u], y = first[v];
    if(x > y) swap(x, y);
    int res = RMQ(x, y);
    return ver[res];
}

int DFS(int u, int fa) {
    for(int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        DFS(v, u);
        num[u] += num[v];
    }
    return 0;
}

int main() {
    int t;
    int cas = 0;
    int n, m;
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d%d", &n, &m);
        int u, v;
        for(int i = 0; i < n-1; i++) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        
        // 初始化LCA所需数组
        tot = 0;
        dfs(1, 1);
        ST(2 * n - 1);
        
        for(int i = n; i <= m; i++) {
            scanf("%d%d", &u, &v);
            int tt = LCA(u, v);
            num[u]++;
            num[v]++;
            num[tt] -= 2; // 一条边两个端点 贡献为2
        }
        
        DFS(1, 1);
        int ans = INF;
        for(int i = 2; i <= n; i++) {
            ans = min(ans, num[i] + 1);
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
/*
1
6 7
1 2
2 3
3 4
4 5
5 6
6 7
1 3
4 6
输出应该是：1 。。。
*/