/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-08 22:24:47
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
int main() {
    ll n;
    cin >> n;
    vector<ll>prime_disvor;
    for(ll p = 2; p * p <= n; p++) {
        if(n % p == 0) {
            prime_disvor.push_back(p);
        }
        while(n % p == 0) {
            n /= p;
        }
    }
    if(n > 1) {
        prime_disvor.push_back(n);
    }
    if(prime_disvor.size() == 1) {
        cout << prime_disvor.front() << endl;
    }
    else if(prime_disvor.size() > 1) {
        cout << 1 << endl;
    }
    else {
        cout << n << endl;
    }
    return 0;
}