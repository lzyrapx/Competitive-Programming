#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 55555;

int sum[maxn << 2];
int x[maxn];

// 把当前结点的信息更新到父结点
void pushup(int rt) {
    // 线段树是用数组来模拟树形结构
    // 对于每一个节点rt,左子节点为 2*rt (一般写作rt<<1)右子节点为 2*rt+1（一般写作rt<<1|1）
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    sum[rt] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);        // 递归构造左子树
    build(mid + 1, r, rt << 1 | 1); // 递归构造右子树
    pushup(rt);                     // 更新求和
}

// 单点增
void update(int p, int l, int r, int rt) {
    if (l == r) {
        sum[rt]++;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) update(p, l, mid, rt << 1);
    else update(p, mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

// 区间求逆序数
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
    int n;
    while (~scanf("%d", &n)) {
        build(0, n - 1, 1);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
            sum += query(x[i], n - 1, 0, n - 1, 1);
            update(x[i], 0, n - 1, 1);
        }
        int ans = sum;
        for (int i = 0; i < n; i++) {
            sum = sum - x[i];      // 减少了的逆序数
            sum = sum + n - x[i] - 1; // 增加了的逆序数
            ans = min(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}