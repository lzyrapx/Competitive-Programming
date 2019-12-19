/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-18 13:42:03
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int a[6] = {15, 16, 17, 18, 19, 20};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        if (x <= 14)
        {
            cout << "NO" << endl;
            continue;
        }
        int f = 0;
        for (int i = 0; i < 6; i++)
        {
            if ((x - a[i]) % 14 == 0) // 一个骰子总点数为21,被遮住相对面的点数永远为７,剩下14,　所以考虑最上面的骰子a[i]就可以了
            {
                f = 1;
                cout << "YES" << endl;
                break;
            }
        }
        if (!f)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}