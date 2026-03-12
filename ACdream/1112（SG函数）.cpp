/*
* this code is made by LzyRapx
* Problem: 1112
* Verdict: Accepted
* Submission Date: 2017-07-24 17:34:31
* Time: 1368MS
* Memory: 21196KB
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000005;
int flag[N];
int sg[100], n;
bool vis[100];
  
void make_prime()
{
    for(int i = 2; i < N; i++)
    {
        if(!flag[i])
        {
            for(int j = i + i; j < N; j += i) flag[j] = i;
        }
    }
         
}
void SG()
{
    sg[0] = 0;
    for(int i = 1; i < 100; i++)
    {
        memset(vis, false, sizeof(vis));
        for(int j = 0; j < i; j++)
        {
            vis[sg[j]] = true;
        }
        for(int j = 1; j < i; j++){
            vis[sg[j] ^ sg[i - j]] = true;
        }
        for(int j = 0;;j++)
        {
            if(!vis[j])
            {
                sg[i] = j;
                break;
            }
        }
    }
}
int solve(int x)
{
    int ret = 0;
    while(flag[x]){
        ret ++;
        x /= flag[x];
    }
    return ret + 1;
}
int main()
{
    SG();
    make_prime();
    while(~scanf("%d", &n))
    {
        int ans = 0;
        for(int i = 0, x; i < n; i++)
        { 
            scanf("%d", &x);
            int cnt = solve(x);
            ans ^= sg[cnt];
        }
        puts(ans ? "Alice" : "Bob");
    }
    return 0;
}