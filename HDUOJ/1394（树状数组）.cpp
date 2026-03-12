#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 5010;
int a[maxn];
int n;
int c[maxn];

int lowbit(int x) { 
    return x & -x; 
}

void add(int i, int val) {
    while (i <= n) {
        c[i] += val;
        i += lowbit(i);
    }
}

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}

int main() {
    while (~scanf("%d", &n)) {
        int ans = 0;
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i]++;
            ans += sum(n) - sum(a[i]);
            add(a[i], 1);
        }
        int MIN = ans;
        for (int i = 1; i <= n; i++) {
            ans -= a[i];        // 减少的逆序数
            ans += n - a[i] + 1; // 增加的逆序数
            if (ans < MIN) MIN = ans;
        }
        cout << MIN << endl;
    }
    return 0;
}