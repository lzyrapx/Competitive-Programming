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
typedef long long LL;
typedef double db;
int T, n, mod, c, t, a[4][4], b[4][4];
LL m;
void mult(int a[4][4], int b[4][4]) {
    LL c[4][4]; memset(c, 0, sizeof(c));
    Rep(i, 1, 2)
        Rep(k, 1, 2)
            Rep(j, 1, 2) (c[i][j] += a[i][k] * b[k][j]) %= mod;
    Rep(i, 1, 2)
        Rep(j, 1, 2) a[i][j] = c[i][j];
}
int main()
{
    scanf ("%d", &T);
    while (T --) {
        scanf ("%d%lld%d%d", &n, &m, &mod, &c);
        a[1][1] = 10, a[1][2] = a[2][2] = b[1][1] = 1;
        a[2][1] = b[1][2] = 0;
        while (m) {
            if (m & 1) mult(b, a);
            mult(a, a), m >>= 1;
        }
        // cout << a[1][1]<< endl;
        printf("Case #%d:\n", ++ t);
        if (b[1][2] * n % mod == c) puts("Yes");
        else puts("No");
    }

    return 0;
}