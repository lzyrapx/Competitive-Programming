/*
* this code is made by LzyRapx
* Problem: 1113
* Verdict: Accepted
* Submission Date: 2017-08-28 14:47:48
* Time: 160MS
* Memory: 2632KB
*/
#include<bits/stdc++.h>
using namespace std;
double dp[123456];
int main()
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=n-1;i>=0;--i)
		{
			int tot = 0;
			double tmp = 0;
			for(int j=1;j<=6;j++)
			{
				if(i+j>n)tot++;
				else 
				{
					dp[i] += dp[i+j];
				} 
			}
		//	printf("dp[%d]=%d\n",i,dp[i]); 
			//cout<<"tot="<<tot<<endl;
			dp[i] += 6;
			dp[i] /= (6-tot);
		//	printf("dp[%d]=%d\n",i,dp[i]); 
		}
		printf("%.2lf\n",dp[0]);
	}
	
	return 0;
 } 
     
    return 0;
 }