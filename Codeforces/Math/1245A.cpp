/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-13 18:02:14
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

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(gcd(a, b) == 1) {
            cout << "Finite" << endl;
        } else {
            cout << "Infinite" << endl;
        }

    }
    return 0;
}