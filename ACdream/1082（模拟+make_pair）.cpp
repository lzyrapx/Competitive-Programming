/*
* this code is made by LzyRapx
* Problem: 1082
* Verdict: Accepted
* Submission Date: 2017-07-26 15:34:20
* Time: 2652MS
* Memory: 7624KB
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn =1234;
int sum[maxn][maxn];
pair<int,int>ask[maxn];
int main()
{
    int x1,x2,y1,y2;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>m>>n;
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int x;
                cin>>x;
                sum[i][j] = x + sum[i-1][j] + sum[i][j-1] -sum[i-1][j-1]; 
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            int k;
            cin>>k;
            int x,y;
            for(int i=0;i<k;i++)
            {
                cin>>y>>x;
                ask[i] = make_pair(x,y);
            }
            int ans = 0;
            for(int i=0;i<k;i++)
            {
                x1 = ask[i].first;
                y1 = ask[i].second;
                x2 = ask[(i+1)%k].first;
                y2 = ask[(i+1)%k].second;
                if(x1 == x2)
                {
                    ans += sum[x1][y1] - sum[x1][y2];
                } 
            }
            printf("%d\n",ans);
        }
         
    }
    return 0;
}