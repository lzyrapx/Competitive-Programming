/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-19 14:07:38
 */ 
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int x[123], y[123];
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }
        int ans = 1e9;
        for(int i = 1; i <= n; i++) {
            int k = m / x[i];
            if(m % x[i] > 0) {
                k++;
            }
            int t = k * y[i];
            ans = min(ans, t);
        }
        cout << ans << endl;
    }
    return 0;
}