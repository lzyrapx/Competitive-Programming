/*
* this code is made by LzyRapx
* Problem: 1063
* Verdict: Accepted
* Submission Date: 2017-07-15 22:28:36
* Time: 556MS
* Memory: 14556KB
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 550000+10;
ll ch[maxn][2];
ll val[maxn];
int sz;
 
void init()
{
    sz = 1;
    memset(ch[0],0,sizeof(ch[0]));
}
void insert(ll x)
{
    int u = 0;
    for(int i=26;i>=0;--i)
    {
        int c = (x>>i)&1;
    //  cout<<"c="<<c<<endl; 
        if(!ch[u][c])
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz] = 0;
            ch[u][c] = sz++;
        }
        u=ch[u][c];
         
    }
//  cout<<"u="<<u<<endl;
    val[u] = x;
}
ll qmax(ll x)
{
    int u = 0;
    for(int i=26;i>=0;--i)
    {
        int c = (x>>i)&1;
        if(ch[u][c^1])u=ch[u][c^1];
        else u = ch[u][c];
    }
    return val[u];
}
ll qmin(ll x)
{
    int u = 0 ;
    for(int i=26;i>=0;--i)
    {
        int c = (x>>i)&1;
        if(ch[u][c])u=ch[u][c];
        else u = ch[u][c^1];
    }
    return val[u];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        init();
        char op[15];
        int x;
        ll tmp,treex;
        for(int i=0;i<n;i++)
        {
            scanf("%s%d",op,&x);
            treex = x;
            if(op[0]=='i')
            {
                insert(treex);
            }
            else if(op[2]=='a')//max
            {
                tmp = qmax(treex);
                printf("%lld\n",tmp^treex); 
            }
            else if(op[2]=='i')//min 
            {
                tmp = qmin(treex);
                printf("%lld\n",tmp^treex);
            }
        }
    }
    return 0;
 }