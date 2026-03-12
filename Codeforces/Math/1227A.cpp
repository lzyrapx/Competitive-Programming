/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-30 23:40:24
 */
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int l, r;
        int maxl = 0;
        int minr = 1e9;
        for(int i = 0; i < n; i++) {
            cin >> l >> r;
            maxl = max(maxl,l);
            minr = min(minr, r);
        }
        cout << max(0, maxl - minr) << endl;
    }
    return 0;
}
