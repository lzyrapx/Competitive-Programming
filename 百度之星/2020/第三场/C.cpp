/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-26 23:35:38
 */ 
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll res = 0;
        m = min(m, n / 2);
        res = m * (2 * n + 1);
        res = res - 2 * m * (m + 1);
        cout << res << endl;
    }
    return 0;
}