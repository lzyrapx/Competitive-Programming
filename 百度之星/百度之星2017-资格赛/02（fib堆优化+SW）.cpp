#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 3e3 + 10;
const int inf = 0x3f3f3f3f;
#define MP make_pair
#define pii pair<int, int>
#define PB push_back

int vis[N], wet[N], combine[N], g[N][N];
bool check[N];
vector<int> G[N];

int s, t, minCut, n;

struct node {
  int x, y;
  bool operator < (const node &rhs) const {
    return y < rhs.y;
  }
};

void Search(int n, int x){
  priority_queue<node> q;
  int Max;
  for(int i = 1; i <= n; ++i) if (!combine[i]) vis[i] = wet[i] = 0, q.push(node{i, 0});
  s = t = -1;
  n -= x;
  for(int i = 1; i <= n; i++) {
    node u = q.top(); q.pop();
    while(vis[u.x]) u = q.top(), q.pop();
    if(t == u.x) return;
    s = t; t = u.x;
    vis[u.x] = 1;
    minCut = u.y;
    for (int j = 0; j < G[t].size(); ++j) {
      int v = G[t][j], w = g[t][v];
      if (!combine[v] && !vis[v]) {
        wet[v] += w;
        q.push(node{v, wet[v]});
      }
    }
  }
}

int Stoer_Wagner(){
  memset(combine, 0, sizeof(combine));
  int ans = inf;
  for(int i = 1; i < n; i++) {
    Search(n, i - 1);
    if (minCut < ans) ans = minCut;
    combine[t] = 1;
    memset(check, 0, sizeof(check));
    for (int k = 0; k <G[s].size(); ++k) {
      int j = G[s][k];
      if(!combine[j])
        check[j] = 1;
    }
    for (int k = 0; k <G[t].size(); ++k) {
      int j = G[t][k];
      if(!combine[j] && !check[j] && j != t) {
        G[s].PB(j);
        G[j].PB(s);
      }
    }
    for (int j = 1; j <= n; j++) {
      g[s][j] += g[t][j];
      g[j][s] += g[j][t];
    }
  }
  return ans;
}

int main()
{
  int a, b, c, m;
  while(scanf("%d%d", &n, &m) != EOF){
    for(int i = 1; i <= n; ++i) G[i].clear();
    memset(g, 0, sizeof(g));
    while(m--){
      scanf("%d%d%d", &a, &b, &c);
      if(!g[a][b]) {
        G[a].PB(b);
        G[b].PB(a);
      }
      g[a][b] += c;
      g[b][a] += c;
    }
    printf("%d\n", Stoer_Wagner());
  }
  return 0;
}