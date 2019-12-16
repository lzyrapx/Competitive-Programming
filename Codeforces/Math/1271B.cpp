/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-16 15:51:03
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i <= 1; i++)
    {
        char x = "WB"[i];
        string t = s;
        vector<int> ve;
        for (int j = 0; j + 1 < n; j++)
        {
            if (t[j] != x)
            {
                t[j] ^= 'w' ^ 'B';
                t[j + 1] ^= 'W' ^ 'B';
                ve.push_back(j + 1);
            }
        }
        if (t.back() == x)
        {
            cout << ve.size() << endl;
            for (auto v : ve)
            {
                cout << v << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}