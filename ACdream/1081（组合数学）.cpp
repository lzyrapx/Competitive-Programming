/*
* this code is made by LzyRapx
* Problem: 1081
* Verdict: Accepted
* Submission Date: 2017-07-23 17:40:10
* Time: 604MS
* Memory: 33544KB
*/
/*
直接数学公式搞。

n个非负整数的和为m的解个数为C(n+m-1,n-1)

如果其中一个位置选择了i, 那么其余的就是C(n-1 + m-i – 1, n-2), 
这就是这个位置i出现次数，  然后位置有n个，再乘以n.

根据欧拉定理，指数对 1e9+6取模。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
const int mod = 1e9+7;
ll C[2020][2020];
void init()
{
    C[0][0] = 1;
    for(int i=1;i<2020;i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++)
        {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
            if(C[i][j] >= mod - 1)
            {
                C[i][j] -= mod - 1;
            }
        }
    }
}
ll q_mod(ll a,ll b)
{
    ll ans = 1;
    a = a%mod;
    while(b)
    {
        if(b&1)
        {
            ans = ans * a %mod; 
        }
        b>>=1;
        a = a*a%mod; 
    }
    return ans;
}
int main()
{
    int t;
    int n,m;
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n==1)
        {
            printf("%d\n",m);
            continue;
        }
        ll ans = 1;
        for(int i=1;i<=m;i++)
        {
            ans*=q_mod(i,1LL * C[n-1+m-i-1][n-2] * n % (mod-1));
            ans %= mod; 
        }
        printf("%lld\n",ans); 
    }
    return 0;
}