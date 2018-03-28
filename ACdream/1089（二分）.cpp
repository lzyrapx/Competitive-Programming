/*
* this code is made by LzyRapx
* Problem: 1089
* Verdict: Accepted
* Submission Date: 2017-06-20 14:12:37
* Time: 924MS
* Memory: 2532KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
vector<int>G[12345];
int in[12345];
int x[12345],y[12345],w[12345];
int n,m;
bool check(int zhishang)
{
    for(int i=0;i<n;i++){
        G[i].clear();
        in[i] = 0;
    }
    for(int i = 0; i < m ; i++)
    {
        int a = x[i] - 1;
        int b = y[i] - 1;
        int c = w[i];
        if(c > zhishang )
        {
            G[b].push_back(a);
            in[a]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt++;
        for(int i = 0; i< G[u].size();i++)
        {
            int v = G[u][i];
            in[v]--;
            if(in[v] == 0){ q.push(v);}
        }
    }
    if(cnt==n)return true;
    else return false;
}
int main()
{   
    int t ;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>x[i]>>y[i]>>w[i];
        }
        int l=0;
        int r=1e9;
        int mid;
    //  while(l < r)//二分智商 //332ms
        for(int i=1;i<=100;i++) //964ms 
        {
            int mid = (l+r)>>1;
            if(check(mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        cout<<l<<endl;
    }
    return 0;
}