/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-26 23:35:54
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
        ll m1 = 0, m2 = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            ll op, v;
            cin >> op >> v;
            if(op == 1){
                m1 = max(m1, v);
            } else {
                m2 = max(m2, v);
            }
        }
        if(m2 == 0) {
            cout << m1 + 1 << endl;
        } else if(m1 == 0) {
            cout << m2 + 2 << endl;
        } else if(m2 >= m1){
            cout << m2 + 2 << endl;
        } else {
            cout << max(m1 + 1, m2 + 3) << endl;
        }
    }
    return 0;
}