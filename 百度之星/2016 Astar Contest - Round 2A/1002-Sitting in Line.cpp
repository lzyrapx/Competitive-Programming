#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define v g[i].y
using namespace std;
typedef long long ll;
typedef double db;
const int N = 18, M = 1 << 16, inf = 2147483647;
int T, n, sn, t, f[N][M][N], a[N], m, b[N], c[N], ans;
int d(int x) { return 1 << x - 1; }
int main()
{
    scanf ("%d", &T);
    while (T --) {
        memset (c, 0, sizeof(c));
        m = 0;
        scanf ("%d", &n);
        Rep(i, 1, n) {
            int x, y;
            scanf ("%d%d", &x, &y);
            if (y == -1) a[++ m] = x;
            else y ++, b[y] = x, c[y] = 1;
        }
        sn = (1 << m) - 1;
        Rep(i, 0, n) Rep(j, 0, sn) Rep(k, 0, m) f[i][j][k] = -inf;
        f[0][0][0] = 0;
        a[0] = 0;
        Rep(i, 1, n) {
            Rep(s, 0, sn) {
                Rep(j, 0, m) if (f[i - 1][s][j] > -inf) {
                    // cout << i - 1 <<" "<<s<<" "<<j<<endl;
                    int z = f[i - 1][s][j];
                    if (c[i]) {
                        f[i][s][0] = max(f[i][s][0], z + a[j] * b[i]);
                        continue ;
                    }
                    Rep(k, 1, m) if (!(d(k) & s)) {
                        f[i][s | d(k)][k] = max(f[i][s | d(k)][k], z + a[k] * a[j]);
                    }
                }
            }
            if (c[i]) a[0] = b[i];
        }
        printf("Case #%d:\n", ++ t);
        ans = -inf;
        Rep(i, 0, m) ans = max(ans, f[n][sn][i]);
        printf("%d\n", ans);
    }

    return 0;
}