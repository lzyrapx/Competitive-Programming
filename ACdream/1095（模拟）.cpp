/*
* this code is made by LzyRapx
* Problem: 1095
* Verdict: Accepted
* Submission Date: 2017-06-20 23:22:10
* Time: 16MS
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
    ll a;
    char s[123];
    while(t--)
    {
        cin>>a;
        int g = 0;
        memset(s,0,sizeof(s));
        while(a)
        {
            if(a&1){
                s[g++] = '1';
            }
            else s[g++] = '0';
            a>>=1;
         }
         int m = 0;
         while(s[m]==0){
            m++;
         }
         ll ans = 1;
         a = 0;
         for(int i=g-1;i>=m;--i)
         {
            a+=((s[i]-'0')*ans);
            ans*=2;
         }
         cout<<a<<endl;
    }
    return 0;
}