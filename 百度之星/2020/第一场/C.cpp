/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-19 14:19:11
 */
#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1234][1234];

int read()
{
    int v = 0, f = 1;
    char c =getchar();
    while( c < 48 || 57 < c ){
        if(c=='-') f = -1;
        c = getchar();
    }
    while(48 <= c && c <= 57) 
        v = v*10+c-48, c = getchar();
    return v*f;
}

int main(int argc, char const *argv[])
{   
    dp[1][1] = 1;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            int gcd = __gcd(i, j);
            int v = 0;
            if(gcd == 1) {
                v = 1;
            }
            if(i - 1 >= 1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + v);
            }
            if(j - 1 >= 1) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + v);
            }
        }
    }
    int t = 0;
    t = read();
    while(t--) {
        int n, m;
        n = read(), m = read();
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
