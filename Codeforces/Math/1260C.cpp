/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-30 22:34:10
 */
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        long long r, b, k;
        cin >> r >> b >> k;
        if(r > b) {
            swap(r, b);
        }
        if(r == b) {
            cout << "OBEY" << endl;
            continue;
        }
        long long g = gcd(r, b);
        r /= g;
        b /= g;
        if((k - 1) * r + 1 >= b) {
            cout << "OBEY" << endl;
        }
        else {
            cout << "REBEL" << endl;
        }
    }
    return 0;
}
