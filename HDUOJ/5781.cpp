#include<bits/stdc++.h>
using namespace std;
const double INF = 1e12;
const double eps = 1e-8;
double dp[2010][20];
double solve(int k, int w)
{
    if(k == 0)
        return dp[k][w] = 0;
    if(w == 0)
        return INF;
    if(dp[k][w] > 0)
        return dp[k][w];
    dp[k][w] = INF;
    for(int i=1; i<=k; i++)
        dp[k][w] = min(dp[k][w],(double)(k-i+1)/(k+1)*solve(k-i,w)+(double)i/(k+1)*solve(i-1,w-1)+1);
    return dp[k][w];
}
int main()
{
    int k, w;
    while(~scanf("%d%d",&k,&w))
    {
        w = min(w,15);
        printf("%.6lf\n",solve(k,w));
    }
    return 0;
}