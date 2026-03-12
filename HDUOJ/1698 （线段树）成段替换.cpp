#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int sum[maxn << 2];
int col[maxn << 2];
int n, m;

// 把当前结点的信息更新到父结点
void pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

// 把当前结点的信息更新到子节点
void pushdown(int rt, int m) {
    if (col[rt]) {
        col[rt << 1] = col[rt << 1 | 1] = col[rt];
        sum[rt << 1] = (m - (m >> 1)) * col[rt];
        sum[rt << 1 | 1] = (m >> 1) * col[rt];
        col[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    col[rt] = 0;
    sum[rt] = 1;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);      // 递归构造左子树
    build(mid + 1, r, rt << 1 | 1); // 递归构造右子树
    pushup(rt);                   // 更新
}

// 成段替换
void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        col[rt] = c;
        sum[rt] = c * (r - l + 1);
        return;
    }
    pushdown(rt, r - l + 1);
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, c, l, mid, rt << 1);
    if (R > mid) update(L, R, c, mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

int main() {
    int t;
    int cas = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        build(1, n, 1);
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            update(a, b, c, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", cas++, sum[1]);
    }
    return 0;
}