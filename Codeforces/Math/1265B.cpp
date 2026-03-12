/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-08 23:00:56
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 123;
int pos[maxn];
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        int n;
        string ans = "";
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            pos[x] = i;
        }
        int l = n + 1;
        int r = 1;
        for(int i = 1; i <= n; i++) {
            l = min(l, pos[i]);
            r = max(r, pos[i]);
            if(r - l + 1 == i) {
                ans += '1';
            }
            else {
                ans += '0';
            }
        }
        cout << ans << endl;
    }

    return 0;
}