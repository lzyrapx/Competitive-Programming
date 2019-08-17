#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pii pair<int, int>
#define INF 0x3f3f3f3f
typedef __gnu_pbds::priority_queue<pii> heap;

heap::point_iterator id[3010];

int n, m;
int d[3010], pa[3010], combine[3010], cost[3010][3010], done[3010], wet[3010], has_edge[3010][3010];
vector<int> G[3010];

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int s, t, cut;


void search() {
    heap q;
    memset(done, 0, sizeof(done));
    memset(wet, 0, sizeof(wet));
    for(int i = 1; i <= n; i++)
        id[i] = NULL;

    for(int i = 1; i <= n; i++) {
        if(!combine[i]) {
            id[i] = q.push(make_pair(0, i));
        }
    }

    s = t = -1;
    while(!q.empty()) {
        int x = q.top().second;
        cut = q.top().first;
        q.pop();

        done[x] = 1;
        s = t, t = x;
        for(int i = 0; i < G[x].size(); i++) {
            int v = G[x][i];
            if(done[v] == 0 && combine[v] == 0) {
                q.modify(id[v], make_pair(wet[v] + cost[x][v], v));
                wet[v] += cost[x][v];
            }
        }
    }
}


int stoer_wanger() {
    memset(combine, 0, sizeof(combine));
    int ans = INF;
    for(int i = 0; i < n - 1; i++) {
        search();
        ans = min(ans, cut);
        if(ans == 0) return 0;
        combine[t] = 1;

        for(int i = 0; i < G[t].size(); i++) {
            int v = G[t][i];
            if(has_edge[s][v] || combine[v]) continue;
            has_edge[s][v] = 1;
            G[s].push_back(v);
        } 

        for(int j = 1; j <= n; j++) if(combine[j] == 0) {
            cost[s][j] += cost[t][j];
            cost[j][s] += cost[j][t];
            if(has_edge[j][t] && has_edge[j][s] == 0) {
                has_edge[j][s] = 1;
                G[j].push_back(s);
            }
        }
    }
    return ans;
}

int main() {
    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; i++) {
            G[i].clear();
            pa[i] = i;
        }

        memset(cost, 0, sizeof(cost));
        memset(has_edge, 0, sizeof(has_edge));

        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(v);
            G[v].push_back(u);
            has_edge[u][v] = has_edge[v][u] = 1;
            cost[u][v] += w;
            cost[v][u] += w;

            int x = findset(u), y = findset(v);
            if(x != y) {
                pa[x] = y;
            }
        }

        for(int i = 1; i <= n; i++) {
            sort(G[i].begin(), G[i].end());
            G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(pa[i] == i) cnt++;
        }

        if(cnt != 1) {
            puts("0");
            continue;
        }

        printf("%d\n", stoer_wanger());
    }
    return 0;
}