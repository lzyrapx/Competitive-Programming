/*
* this code is made by LzyRapx
* Problem: 1096
* Verdict: Accepted
* Submission Date: 2017-06-20 15:37:15
* Time: 380MS
* Memory: 1664KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
int main()
{
    int n;
    scanf("%d",&n);
    ll ans = 0;
    ll tmp;
    for(int i=0;i<n;i++){
        scanf("%lld",&tmp);
        ans^=tmp;
    }
    for(int i=0;i<n-1;i++){
        scanf("%lld",&tmp);
        ans^=tmp;
    }
    cout<<ans<<endl;
    return 0;
}