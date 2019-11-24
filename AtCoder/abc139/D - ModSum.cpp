
#include <bits/stdc++.h>

using namespace std;

// {1, 2, 3} => {3, 1, 2} => 3
// {1, 2, 3 4 } => {4, 1, 2, 3} => 6
int main()
{
    long long n;
    cin >> n;
    cout << n * (n - 1) / 2 << endl;
    return 0;
}