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
int T;
ll l, r;
ll work(ll x) {
    // int y = x, z = 0;
    // while (y) z += y & 1;
    ll ans = 0, b = 0, d = 0;
    while (x) {
        if (x & 1) ans += b + ((x >> 1 & 1) == 0);
        // cout << x <<" "<<ans<<" "<<(x >> 1 & 1)<<" "<<b<<" "<<(x & 1)<< endl;
        b = d = b + d, b ++;
        x >>= 1;
    }
    return ans;
}
int main()
{
    scanf ("%d", &T);
    while (T --) {
        scanf ("%I64d%I64d", &l, &r);
        printf("%I64d\n", work(r) - work(l - 1));
    }

    return 0;
}