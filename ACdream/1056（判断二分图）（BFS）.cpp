/*
* this code is made by LzyRapx
* Problem: 1056
* Verdict: Accepted
* Submission Date: 2017-06-06 22:53:47
* Time: 68MS
* Memory: 1704KB
*/
#include <bits/stdc++.h>
using namespace std;
map<string,int>color;
map<string,vector<string> >G;
 
int bfs(string source)
{
    string u,v;
    u=source;
    color[source] = 1;
    queue<string>q;
    q.push(source);
     
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            v = G[u][i];
            if(color[v] == -1 && color[u] != color[v])
            {
                color[v] = 1-color[u];
                q.push(v);
            }
            else if (color[v] == color[u])
            {
                return 0;
            }
        }
    }
    return 1;
} 
int main()
{
    int cas=1,t;
    cin>>t;
    int n;
    string s1,s2;
    while(t--)
    {
        cin>>n;
        G.clear();
        color.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>s1>>s2;
            G[s1].push_back(s2);
            G[s2].push_back(s1);
            color[s1]=color[s2]=-1;
        }
        printf("Case #%d: ",cas++);
        if(bfs(color.begin()->first))
        {
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
    return 0;
}