/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-22 02:23:35
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
    int n;
    cin >> n;
    if(n == 1) {
        cout << "21" << " " << "20" << endl;
        return 0;
    }
    for(int i = n; i <= 1e9; i++) {
        if((i - n) != 0 && (i - n) > 2 && (i - n) % 2 == 0 && (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)) {
            cout << i << " " << i - n << endl;
            return 0;
        }
    }
    return 0;
}