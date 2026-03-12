/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-11 23:22:41
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int s[123];
int sz;
// 因为s序列固定对应的数唯一,数对应的s序列也唯一
// 计算满足条件的序列有几个就是计算数有几个
// 条件：设第 i 位是第 i 次操作的结果，则s[i] < i,且最后一位不能位0
// 做法：先按最后一位可以为 0 来算，最后减去一个0算一遍，再减去即可
ll calc(){
    ll ans = 1;
    for(int i = 1; i <= sz; i++) { // s[i] 肯定要小于 i+1, 因为余数不可能大于除数
       ll tp = 0;
       for(int j = 1; j <= sz; j++) {
           if(s[j] < i + 1){
               tp++;
           }
       }
       // 第i位有 tp 个数放的可能,但前面 i-1 位已经用掉了 i-1 个数, s[i] <= s[i + 1]
       ans *= (tp - (i - 1));
    }
    // cerr << ans << endl;
    // 去掉重复数的重复计算。比如 1，1，2这些
    int f = 0;
    for(int i = 1; i <= sz; i++) {
        if(s[i] == s[i - 1]) f++;
        else f = 1;
        ans /= f;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        sz = 0;
        int k = 2;
        memset(s, 0, sizeof(s));
        while(n > 0) {
            s[++sz] = n % k;
            n /= k;
            k++;
        }
        cerr << "sz = " << sz << endl;
        sort(s + 1, s + 1 + sz);
        ll ans = calc();
        if(s[1] == 0) {
            for(int i = 1; i <= sz; i++) {
                s[i] = s[i + 1];
            }
            sz -= 1;
            ans -= calc(); // 末尾不能有 0 的时候
        }
        cout << ans - 1 << endl;
    }
    return 0;
}

