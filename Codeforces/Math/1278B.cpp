/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-22 02:49:30
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;

const ll mod = 998244353;
const int maxn = 2 * 1e5 + 123;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        for(int i = 0; ; i++) {
            ll p = a + 1LL * i * (i + 1) / 2;
            ll q = a - 1LL * i * (i + 1) / 2;
            if(b >= q && b <= p && (p + b) % 2 == 0) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}