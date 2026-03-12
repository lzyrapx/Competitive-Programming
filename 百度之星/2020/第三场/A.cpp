/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-26 23:35:09
 */ 
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        double res = 0.0;
        int a;
        double b;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            res = max(res, (1 - b) / (a - b + 1));
        }
        printf("%.5f\n",res);
    }
    return 0;
}