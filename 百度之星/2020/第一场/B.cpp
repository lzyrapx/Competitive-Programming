/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-19 14:19:11
 */ 
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int v[23], c[23];
int main(int argc, char const *argv[])
{
    
    v[1]=95; c[1]=43;
    v[2]=90; c[2]=40;
    v[3]=85; c[3]=37;
    v[4]=80; c[4]=33;
    v[5]=75; c[5]=30;
    v[6]=70; c[6]=27;
    v[7]=67; c[7]=23;
    v[8]=65; c[8]=20;
    v[9]=62; c[9]=17;
    v[10]=60; c[10]=10;
    v[11]=0; c[11]=0;
    int t = 0;
    cin >> t;
    while(t--) {
        int n;
        int ans = 0;
        cin >> n;
        for(int i = 1; i <= 11; i++) {
            for(int j = 1; j<= 11; j++) {
                for(int k = 1; k <= 11; k++) {
                    for(int l = 1; l <= 11; l++) {
                        if(v[i] + v[j] + v[k] + v[l] <= n) {
                            ans = max(c[i] + c[j] + c[k] + c[l], ans);
                        }
                    }
                }
            }
        }
        cout << ans / 10 << "." << ans % 10 << endl;
    }
   
    return 0;
}