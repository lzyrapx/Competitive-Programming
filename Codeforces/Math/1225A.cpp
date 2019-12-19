/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-17 17:44:51
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

int main()
{
    int da, db;

    cin >> da >> db;
    if (da - db >= 1 && da - db <= 7)
    {
        cout << "-1" << endl;
        return 0;
    }
    if (db - da >= 2)
    {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = da; i <= 1e9; i++)
    {
        if (to_string(i)[0] == to_string(da)[0] && to_string(i + 1)[0] == to_string(db)[0])
        {
            cout << i << " " << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}