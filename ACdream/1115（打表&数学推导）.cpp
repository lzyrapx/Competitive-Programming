/*
* this code is made by LzyRapx
* Problem: 1115
* Verdict: Accepted
* Submission Date: 2017-06-21 23:12:56
* Time: 28MS
* Memory: 1664KB
*/
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
//x + 2 = (a + 2)*(b + 2)
//x = 3^p*5^q
bool check(ll n)
{
    n = n + 2;
    while(n%3==0)n/=3;
    while(n%5==0)n/=5;
    if(n==1)return true;
    else return false;
}
int main()
{  
    ll n;   
    while(~scanf("%lld",&n))
    {
        if(check(n))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}