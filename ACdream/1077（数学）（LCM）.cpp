/*
* this code is made by LzyRapx
* Problem: 1077
* Verdict: Accepted
* Submission Date: 2017-06-19 14:07:07
* Time: 0MS
* Memory: 1664KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
int main()
{
     
    while(~scanf("%lld",&n))
    {
        ans  = 0;
        if(n==1){
            puts("1");continue;
        }
        else if(n==2)
        {
            puts("2");continue;
        }
        else if(n==3)
        {
            puts("6");continue;
        }
        if(n&1){
            ans = 1LL* n * (n-1) * (n-2); 
        }
        else //n为偶数 
        {
            if(n%3==0){
                ans = 1LL*(n-1)*(n-2)*(n-3);
            }
            else ans =1LL*n*(n-1)*(n-3);
        }
        cout<<ans<<endl;
    }
    return 0;
}