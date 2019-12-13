/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-13 17:32:25
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
    while(q--) {
        ll a, b, n, S;
        // x * n + y = S
        // x <= a, y <= b
        cin >> a >> b >> n >> S;
        if(S % n > b) {
            cout << "NO" << endl;
            continue;
        }
        if(a * n + b < S) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}