#include<bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int h, w, n;
int MAX[maxn << 2];

// 把当前结点的信息更新到父结点
void pushup(int rt) {
    // 线段树是用数组来模拟树形结构
    // 对于每一个节点rt,左子节点为 2*rt (一般写作rt<<1)右子节点为 2*rt+1（一般写作rt<<1|1）
    MAX[rt] = max(MAX[rt << 1], MAX[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    MAX[rt] = w;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);     // 递归构造左子树
    build(mid + 1, r, rt << 1 | 1); // 递归构造右子树
}

int query(int x, int l, int r, int rt) {
    if (l == r) {
        MAX[rt] -= x;
        return l;
    }
    int mid = (l + r) >> 1;
    int ans;
    if (MAX[rt << 1] >= x)
        ans = query(x, l, mid, rt << 1);
    else
        ans = query(x, mid + 1, r, rt << 1 | 1);
    pushup(rt);
    return ans;
}

int main() {
    while (~scanf("%d%d%d", &h, &w, &n)) {
        if (h > n) h = n;
        build(1, h, 1);
        while (n--) {
            int x;
            scanf("%d", &x);
            if (MAX[1] < x)
                cout << -1 << endl;
            else
                printf("%d\n", query(x, 1, h, 1));
        }
    }
    return 0;
}