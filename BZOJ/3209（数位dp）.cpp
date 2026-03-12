/**************************************************************
    Problem: 3209
    User: Walker_ACM
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1408 kb
****************************************************************/
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod =1e7+7;
ll n,m;
ll ans[66],dig[60],c[61][61],dp[60][60][2];
int vis[60][60][2];
ll q_mod(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        b>>=1;
        a = a*a%mod;
    }
    return res;
}
ll dfs(int pos,int left,int flag)//left表示有多少个 1 
{
    if(vis[pos][left][flag]==1) return dp[pos][left][flag];
    if(pos + 1 < left) return 0;
    if(left==0) return 1;  
    else{
        ll& res = dp[pos][left][flag];
        if(flag==0)
        {
            if(dig[pos]==0)
            {
                res+=dfs(pos-1,left,flag);
            }
            else
            {
                res+=dfs(pos-1,left,1);
                res+=dfs(pos-1,left-1,0);
            }
        }
         
        else {
            res += c[pos+1][left];
        }
        return res;
    }
}
ll solve(ll x)
{
    int len =0;
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    while(x) dig[len++] = x & 1, x>>=1;
    for(int i=1;i<=len;i++)
    {
        ans[i] = dfs(len-1,i,0); //ans[i]存储的是二进制中有 i个1的数字的个数 
    } 
    return len;
}
int main()
{
    for(int i=0;i<=60;i++){
        c[i][0]=c[i][i] = 1;
        for(int j=1;j<=i-1;j++)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
    while(~scanf("%lld",&n))
    {
        int len = solve(n);
        ll Ans=1;
        for(int i=1;i<=len;i++){
            Ans *= q_mod(i,ans[i]);//二进制表示中有 i个 1的数字的个数=ans[i]
            Ans %= mod;
        }
        printf("%lld\n",Ans);
    }
    return 0;
}