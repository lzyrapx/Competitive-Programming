/*
* this code is made by LzyRapx
* Problem: 1079
* Verdict: Accepted
* Submission Date: 2017-07-26 14:16:04
* Time: 0MS
* Memory: 1676KB
*/
#include<bits/stdc++.h>
using namespace std;
int ans,n;
int dp[1234];
int a[1234];
int main()
{
    cin>>n;
    for (int i=0;i<n;i++) 
    {
        cin>>a[i];
        
    }
	dp[0]=a[0];
    dp[1]=min(a[0],a[1]);
    for (int i=2;i<n;i++) 
    {
        dp[i]=min(a[i],max(dp[i-1],dp[i-2]));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}