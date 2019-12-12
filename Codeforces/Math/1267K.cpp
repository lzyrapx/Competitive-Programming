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

ll fac[23];
int cnt[25];

vector<int> calc(ll x)
{
    vector<int> res;
    for (int i = 2; x; i++)
    {
        res.push_back(x % i);
        x /= i;
    }
    sort(res.begin(), res.end());
    return res;
}
int main(int argc, char const *argv[])
{
    fac[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        fac[i] = fac[i - 1] * i;
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        ll ans = 0;
        vector<int> rem = calc(x);
        for (int i = 0; i < rem.size(); i++)
        {
            if (rem[i])
            {
                ll sum = 1;
                vector<int> ve;
                for (int j = 0; j < rem.size(); j++)
                {
                    if (i != j)
                    {
                        ve.push_back(rem[j]);
                    }
                }
                for (int j = 0; j < ve.size(); j++)
                {
                    cerr << "a = " << max(0, j + 2 - max(1, ve[j])) << " " << ve[j] << endl;
                    sum *= max(0, j + 2 - max(1, ve[j]));
                }
                ans += sum;
            }
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < rem.size(); i++)
        {
            cnt[rem[i]]++;
        }
        for (int i = 0; i < rem.size(); i++)
        {
            ans /= fac[cnt[i]];
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
