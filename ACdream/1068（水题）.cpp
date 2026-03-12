/*
* this code is made by LzyRapx
* Problem: 1068
* Verdict: Accepted
* Submission Date: 2017-06-07 17:24:57
* Time: 0MS
* Memory: 1664KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll a,ll b)
{
    ll ans = 0;
    while(a)
    {
         ans += a%10;
         a /= 10;
    } 
    if(ans == b) return 1;
    return 0;
}
 
int main()
{
    ll a,b,c;
    while(cin>>a>>b>>c)
    {
        for(ll i=a;i<=b;i++)
        {
            if(solve(i,c))
            {
                cout<<i<<endl;break;
            }
        }
    }
    return 0;
}