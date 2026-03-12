/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-13 17:03:51
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

int main() {
    int q;
    cin >> q;
    int a,b,c;
    for(int i = 1; i <= q; i++) {
        cin >> a >> b >> c;
        ll ans = 3e9;
        for(int A = a - 1; A <= a + 1; A++) {
            for(int B = b - 1; B <= b + 1; B++){
                for(int C = c - 1; C <= c + 1; C++) {
                    ans = min(ans, 1LL * (abs(A - B) + abs(A - C) + abs(B - C)));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}