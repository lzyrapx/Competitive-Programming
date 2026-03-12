#include <bits/stdc++.h>
using namespace std;

const int maxn = 55555;
int sum[maxn << 2];

void pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &sum[rt]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

void update(int p, int add, int l, int r, int rt) {
    if (l == r) {
        sum[rt] += add;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) update(p, add, l, mid, rt << 1);
    else update(p, add, mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    int mid = (l + r) >> 1;
    int ans = 0;
    if (L <= mid) ans += query(L, R, l, mid, rt << 1);
    if (R > mid) ans += query(L, R, mid + 1, r, rt << 1 | 1);
    return ans;
}

int main() {
    int T, n;
    int cas = 1;
    scanf("%d", &T);
    while (T--) {
        printf("Case %d:\n", cas++);
        scanf("%d", &n);
        build(1, n, 1);
        char op[10];
        while (scanf("%s", op)) {
            if (op[0] == 'E') break;
            int a, b;
            scanf("%d%d", &a, &b);
            if (op[0] == 'Q') printf("%d\n", query(a, b, 1, n, 1));
            else if (op[0] == 'S') update(a, -b, 1, n, 1);
            else update(a, b, 1, n, 1);
        }
    }
    return 0;
}