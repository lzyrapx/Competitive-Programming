#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define v g[i].y
#define u t[x]
#define Lc t[x << 1]
#define Rc t[x << 1 | 1]
#define flc x << 1, l, mid
#define frc x << 1 | 1, mid + 1, r
using namespace std;
typedef long long ll;
typedef double db;
const ll inf = 1ll << 60;
const int N = 100005;
int T, p, n, m, pos[N], sz, ql, qr, w[N], dfn, in[N], out[N], q, a[N], st[N], top, vis[N], par[N];
ll ans, s[N];
struct edge { int y, nex; } g[N * 2];
void init(int x, int y) { g[++ sz] = (edge) { y, pos[x] }, pos[x] = sz; }
struct segtree { ll mx, lz; } t[N * 8];
void pd(int x) {
    u.mx += u.lz; Lc.lz += u.lz, Rc.lz += u.lz; u.lz = 0;
}
void add(int x, int l, int r) {
    pd(x);
    if (ql > r || qr < l) return ;
    if (ql <= l && r <= qr) {
        u.lz += q; pd(x);
        return ;
    }
    int mid = (l + r) >> 1;
    add(flc); add(frc);
    u.mx = max(Lc.mx, Rc.mx);
}
void qry(int x, int l, int r) {
    pd(x);
    if (ql > r || qr < l) return ;
    if (ql <= l && r <= qr) { ans = max(ans, u.mx); return ; }
    int mid = (l + r) >> 1;
    qry(flc), qry(frc);
}
void dfs() {
    while (top) {
        int x = st[top];
        if (!vis[x]) {
            // cout <<x << endl;
            in[x] = ++ dfn, w[dfn] = x;
            RepE(i, x) if (v != par[x])
                par[v] = x, s[v] = s[x] + a[v], st[++ top] = v;
            vis[x] = 1;
        } else top --, out[x] = dfn;
    }
}
void build(int x, int l, int r) {
    u.lz = 0;
    if (l == r) {
        u.mx = s[ w[l] ];
        return ;
    }
    int mid = (l + r) >> 1;
    build(flc); build(frc);
    u.mx = max(Lc.mx, Rc.mx);
}
int main()
{
    scanf ("%d", &T);
    while (T --) {
        memset(pos, 0, sizeof(pos));
        memset(vis, 0, sizeof(vis));
        sz = dfn = 0; top = 1;
        scanf ("%d%d", &n, &m);
        Rep(i, 1, n - 1) {
            int x, y;
            scanf ("%d%d", &x, &y);
            init(x, y), init(y, x);
        }
        Rep(i, 0, n - 1) scanf ("%d", &a[i]);
        s[0] = a[0];
        dfs();
        build(1, 1, n);
        printf("Case #%d:\n", ++ p);
        Rep(i, 1, m) {
            int ty, x, y;
            scanf ("%d%d", &ty, &x);
            ql = in[x], qr = out[x];
            if (!ty) {
                scanf ("%d", &y);
                q = y - a[x], a[x] = y;
                add(1, 1, n);
            } else {
                ans = -inf;
                qry(1, 1, n);
                printf("%I64d\n", ans);
            }
        }
    }

    return 0;
}