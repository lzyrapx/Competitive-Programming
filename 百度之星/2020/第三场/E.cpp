/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-26 23:36:16
 */ 
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 1001;
const int mod = 1e9 + 7;

ll dp[maxn][maxn][12];

void init() {
    dp[0][0][0] = 1;
    for(int i = 1; i < maxn; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= 10; k++){
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % mod;
            }
            if(j != 0) {
                for(int k = 1; k <= 10; k++) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] * i % mod;
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        if(n == 1) {
            if(m != 0) {
                cout << "-1" << endl;
            }
            else {
                cout << 1 << endl;
            }
            continue;
        }
        ll res = 0;
        for(int i = 0; i <= 10; i++) {
            // cout << "res = " << res << endl;
            res = (res + dp[n - 2][m][i]) % mod;
        }
        if(m > ((n - 2) - (n - 2) / 11)) {
            cout << "-1" << endl;
        } else {
            cout<< res << endl;
        }
    }
    return 0;
}