/*
* this code is made by LzyRapx
* Problem: 1029
* Verdict: Accepted
* Submission Date: 2017-06-05 22:45:56
* Time: 148MS
* Memory: 5524KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
ll a[123456],b[123456],asum[123456],bsum[123456];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        asum[i]=asum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        bsum[i]=bsum[i-1]+b[i];
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans = ( (asum[i-1]%mod) * (b[i]%mod) + (bsum[i-1]%mod) * (a[i]%mod) +(a[i]%mod) * (b[i]%mod) )%mod;
        cout<<ans;
        if(i<n)cout<<" ";
    }
    cout<<endl;
    return 0;
}