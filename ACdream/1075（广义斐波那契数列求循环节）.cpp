/*
* this code is made by LzyRapx
* Problem: 1075
* Verdict: Accepted
* Submission Date: 2017-07-17 23:58:54
* Time: 176MS
* Memory: 1680KB
*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;
//http://blog.csdn.net/ACdreamers/article/details/25616461
struct matrix
{
    ll mat[2][2];
};
ll fac[2][505];
ll n,cnt;
matrix A;
matrix I = {1,0,0,1};
ll pri[6] = {2, 3, 7, 109, 167, 500000003};
ll num[6] = {4, 2, 1, 2, 1, 1};
matrix multi(matrix a,matrix b)
{
    matrix c;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            c.mat[i][j] = 0;
            for(int k=0; k<2; k++)
            {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                c.mat[i][j] %= mod;
            }
        }
    }
    return c;
}
  
matrix power(matrix A,ll n)
{
    matrix ans = I, p = A;
    while(n)
    {
        if(n & 1)
        {
            ans = multi(ans,p);
            n--;
        }
        n >>= 1;
        p = multi(p,p);
    }
    return ans;
}
  
ll q_mod(ll a,ll b)
{
    ll ans = 1;
    a %= mod;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % mod;
            b--;
        }
        a = a * a % mod;
        b >>= 1;   
    }
    return ans;
}
ll Legendre(ll a,ll p)
{
    ll t = q_mod(a,(p-1)>>1);
    if(t == 1) return 1;
    return -1;
}
bool check(matrix A ,ll n)
{
    matrix ans = power(A,n);
    return ans.mat[0][0] == 1 && ans.mat[0][1] == 0 &&
           ans.mat[1][0] == 0 && ans.mat[1][1] == 1;
}
void dfs(int dept,ll product = 1)
{
    if(dept == cnt)
    {
        fac[1][n++] = product;
        return;
    }
    for(int i=0; i<=num[dept]; i++)
    {
        dfs(dept+1,product);
        product *= pri[dept];
    }
}
int main()
{
    fac[0][0] = 1; 
    fac[0][1] = 2;
    fac[0][2] = 500000003;
    fac[0][3] = 1000000006;
    ll a,b,c,d;
    while(~scanf("%d%d%d%d",&a,&b,&c,&d))
    {
        ll t = a * a + 4 * b;
        A.mat[0][0] = a; A.mat[0][1] = b;
        A.mat[1][0] = 1; A.mat[1][1] = 0;
        if(Legendre(t,mod) == 1)
        {
            for(int i=0; i<4; i++)
            {
                if(check(A,fac[0][i]))
                {
                    printf("%lld\n",fac[0][i]);
                    break;
                }
            }
        }
        else
        {
            n = 0;
            cnt = 6;
            dfs(0,1);
            sort(fac[1],fac[1]+n);
            for(int i=0;i < n;i++)
            {
                if(check(A,fac[1][i]))
                {
                    printf("%lld\n",fac[1][i]);
                    break;
                }
            }
        }
    } 
    return 0;
}