/*
* this code is made by LzyRapx
* Problem: 1060
* Verdict: Accepted
* Submission Date: 2017-07-12 19:55:32
* Time: 236MS
* Memory: 1664KB
*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int mod;
struct matrix
{
    ll a[2][2];
    void init()
    {
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
            {
                a[i][j] = (i==j);
            }
        }
    }
};
matrix multi(matrix a,matrix b)
{
    matrix c;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c.a[i][j] = 0;
            for(int k=0;k<2;k++){
                c.a[i][j] += (a.a[i][k]*b.a[k][j]);
                c.a[i][j]%=mod;
            }
        }
    }
    return c;
}
matrix mul(matrix s,ll k)
{
    matrix ans;
    ans.init();
    while(k>=1)
    {
        if(k&1){
            ans = multi(ans,s);
        }
        k>>=1;
        s = multi(s,s);
    }
    return ans;
}
int main()
{
    int t;
    ll n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        matrix s,e;
        s.a[0][0] = 3; s.a[0][1] = 1;
        s.a[1][0] = 1; s.a[1][1] = 0;
        mod = 240;//循环节
        if(n>=2)
        {
            e = mul(s,n-1);
            n = e.a[0][0];
        }
        mod = 183120;//循环节
        if(n>=2)
        {
            e = mul(s,n-1);
            n = e.a[0][0];
        }
        mod = 222222224;//循环节
        if(n>=2)
        {
            e = mul(s,n-1);
            n = e.a[0][0];
        }
        mod = 1000000007;
        if(n>=2)
        {
            e= mul(s,n-1);
            n = e.a[0][0];
        }
        printf("%lld\n",n);
    }    
    return 0;
 }