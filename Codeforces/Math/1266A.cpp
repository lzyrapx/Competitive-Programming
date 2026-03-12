/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-18 13:32:03
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

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.find('0') == -1)
        {
            cout << "cyan" << endl;
            continue;
        }
        int even = 0;
        for (auto c : s)
        {
            if ((c - '0') % 2 == 0)
            {
                even++;
            }
        }
        if (even <= 1)
        {
            cout << "cyan" << endl;
            continue;
        }
        int sum = 0;
        for (auto c : s)
        {
            sum += (c - '0');
        }
        if (sum % 3 == 0)
        {
            cout << "red" << endl;
        }
        else
        {
            cout << "cyan" << endl;
        }
    }
    return 0;
}