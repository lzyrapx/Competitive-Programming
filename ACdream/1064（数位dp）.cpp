/*
* this code is made by LzyRapx
* Problem: 1064
* Verdict: Accepted
* Submission Date: 2017-06-07 09:35:40
* Time: 188MS
* Memory: 1664KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//dp[i][0]表示既没有3也没有8的，
//dp[i][1]表示有3但是没有8的，
//dp[i][2]表示有8但是没有3的
int dp[11][4];
int digit[11];
int check(int s,int dig)
{
    if(dig==3)return s|1;
    if(dig==8)return s|2;
    return s;
}
int solve(int pos,int s,bool limit)
{
    if(pos==-1)return s==1 || s==2;
    if(!limit && dp[pos][s] != -1) return dp[pos][s];
    int res = 0;
    int ed = limit ? digit[pos]:9;
    for(int i=0;i<=ed;i++)
    {
        res += solve(pos-1,check(s,i),limit && i==ed);
    }
    if(!limit) dp[pos][s] = res;
    return res;
}
int cal(int x)
{
    int cnt = 0;
    while(x)
    {
        digit[cnt++] = x%10;
        x/=10;
    }
    return solve(cnt-1,0,1);
}
int main()
{
    int t ;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        int l,r;
         
        cin>>l>>r;
        cout<<cal(r)-cal(l-1)<<endl;
    }
    return 0;
     
}