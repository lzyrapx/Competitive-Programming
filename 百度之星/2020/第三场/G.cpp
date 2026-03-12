/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-26 23:37:04
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


int solve(int first, int second, int third, int x, int y, int z) {
    int res  = min((third + y - 1) / y, (second + z - 1) / z);
    second -= res * z;
    third -= res * y;
    // cout << "second = " << second << endl;
    // cout << "thrid = " << third << endl;
    if(second > 0) {
        res = res + min((first + y - 1) / y, (second + x - 1) / x);
    }
    if(third > 0) {
        res = res + min((first + z - 1) / z, (third + x - 1) / x);
    }
    // cout << "res = " << res << endl;
    return res;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int x,y,z;
        cin >> x >> y >> z;
        // init 1000 blood
        int first = 1000; // left
        int second = 1000; // mid
        int third = 1000; // right
        if(x > z){
            swap(x, z);
        }
        if(y > z){
            swap(y, z);
        }
        if(x > y){
            swap(x, y);
        }
        
        // x < y < z
        int res = 1000 / z;
        second -= res * z;
        third -= res * y;
        int mx1 = solve(1000, second, third, x, y, z);
        int mx2 = solve(third, second, 1000, z, y, x);
        int mx = min(mx1, mx2);
        // cout << "res = " << res << endl;
        // cout << "mx = " << mx << endl;
        cout << res + mx << endl;
    }
    return 0;
}
