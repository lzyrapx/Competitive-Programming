/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-15 22:48:48
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <tuple>
#include <set>

using namespace std;

typedef long long ll;


int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int res = f * min(b, min(c, d)) + e * min(max(d - min(b, min(c, d)), 0), a);
    int ans = e * min(a, d) + f * min(max(d - min(a, d), 0), min(c, b));
    cout << max(res, ans) << endl;
    return 0;
}