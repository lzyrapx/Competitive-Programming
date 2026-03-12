/*
* this code is made by LzyRapx
* Problem: 1115
* Verdict: Accepted
* Submission Date: 2017-06-21 23:20:26
* Time: 64MS
* Memory: 1680KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
set<ll> s;
ll n;
ll cal(ll a, ll b){
    return 2 + 2 * a + 2 * b + a * b;
}
void dfs(ll x)
{
    vector<ll> V;
    for(set<ll>::iterator it = s.begin(); it != s.end(); it++)
    {
        ll ret = cal(x, *it);
        if(ret > inf) break;
        if(s.count(ret) == 0) V.push_back(ret);
    }
    for(int i = 0; i < V.size(); i++) s.insert(V[i]);
    for(int i = 0; i < V.size(); i++) dfs(V[i]);
}
int main(){
      
    s.insert(1);
    s.insert(7);
    s.insert(3);
    dfs(3);
    dfs(7);
    while(~scanf("%lld", &n))
    {
        puts(s.count(n) ? "Yes" : "No");
    }
    return 0;
}