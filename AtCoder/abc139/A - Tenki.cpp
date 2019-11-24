#include <bits/stdc++.h>
using namespace std;
string s;
string t;
int main()
{
    cin >> t;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (s[i] == t[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}