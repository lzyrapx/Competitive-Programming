/*
* this code is made by LzyRapx
* Problem: 1098
* Verdict: Accepted
* Submission Date: 2017-06-20 23:33:16
* Time: 20MS
* Memory: 1664KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+10;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        int r1,r2;
        cin>>a>>b>>r1>>r2;
        if(a<b)swap(a,b);
        if(r1<r2)swap(r1,r2);
        if(2*r1>b){
            puts("NO");
            continue;
        }
        int x = b - r2 - r1;
        int y = a - r2 - r1;
        int z = r1 + r2;
        if(x*x + y*y >= z*z)puts("YES");
        else puts("NO");
    }
    return 0;
}