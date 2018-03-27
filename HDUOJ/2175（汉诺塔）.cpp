#include <bits/stdc++.h>
using namespace std;
long long dfs(long long n,long long m)
{
    if(n==1&&m==1) return 1;
    long long mid=pow(2,n-1);
    if(m==mid) return n;
    else if(m>mid) return dfs(n-1,m-mid);
    else return dfs(n-1,m);
}
int main()
{
    long long n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        cout<<dfs(n,m)<<endl;
    }
    return 0;
}