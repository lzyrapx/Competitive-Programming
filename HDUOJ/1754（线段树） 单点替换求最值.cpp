#include<bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int MAX[maxn << 2];

// 把当前结点的信息更新到父结点
void pushup(int rt) {
    // 线段树是用数组来模拟树形结构
    // 对于每一个节点rt,左子节点为 2*rt (一般写作rt<<1)右子节点为 2*R+1（一般写作rt<<1|1）
    MAX[rt] = max(MAX[rt << 1], MAX[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &MAX[rt]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);      // 递归构造左子树
    build(mid + 1, r, rt << 1 | 1); // 递归构造右子树
    pushup(rt);                  // 更新求和
}

void update(int p, int change, int l, int r, int rt) { // 单点替换
    if (l == r) {
        MAX[rt] = change;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) update(p, change, l, mid, rt << 1);
    else update(p, change, mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt) { // 区间最值
    if (L <= l && r <= R) {
        return MAX[rt];
    }
    int mid = (l + r) >> 1;
    int ans = 0;
    if (L <= mid) ans = max(ans, query(L, R, l, mid, rt << 1));
    if (R > mid) ans = max(ans, query(L, R, mid + 1, r, rt << 1 | 1));
    return ans;
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        build(1, n, 1);
        while (m--) {
            char op[3];
            int a, b;
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'Q')
                printf("%d\n", query(a, b, 1, n, 1));
            else
                update(a, b, 1, n, 1);
        }
    }
    return 0;
}