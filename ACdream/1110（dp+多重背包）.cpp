/*
* this code is made by LzyRapx
* Problem: 1110
* Verdict: Accepted
* Submission Date: 2017-07-23 12:55:13
* Time: 1992MS
* Memory: 2836KB
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n,cap;
int a[maxn],b[maxn];
int dp[maxn];
 
int main()
{
    int t ;
    scanf("%d",&t);
    for(int i =1;i<=t;i++)
    {
        printf("Case %d: ",i);
        scanf("%d%d",&n,&cap); 
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=cap;i++){
            dp[i] = -1;
        }
        dp[0] = 0;
         
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=cap;j++)
            {
                if(dp[j]!=-1){
                    dp[j] = 0;
                }
            }
            for(int j = 0;j <= cap;j++)      
            {
                if(dp[j] == -1)continue;
                if(dp[j] > b[i])
                {
                    dp[j] = -1;continue;
                }
                if(j + a[i] <= cap && (dp[ j + a[i] ] == -1 || dp[ j + a[i] ] >= dp[j] + 1))
                {
                    dp[j+a[i]] = dp[j] + 1; 
                }  
            }
        }
        int ans = 0;
        for(int i=1;i<=cap;i++)
        {
        //  cout<<"dp["<<i<<"]="<<dp[i]<<endl;
            if(dp[i] != -1)
            {
                ans ++;
            }
        }
        cout<<ans<<endl;
         
    }
    return 0;
 }