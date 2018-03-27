#include<bits/stdc++.h>
using namespace std;
int dp[5005][5005];
//dp[i][j]表示前 j 支筷子取 i 对筷子的最小 badness，不考虑第三根筷子 
int main()
{
   	int t;
   	cin>>t;
   	while(t--)
   	{
   		int n,k;
   		cin>>k>>n;
   		k+=8;
   		vector<int>L(n+1); 
   		for(int i=n;i>=1;--i){//从大到小 
   			cin>>L[i];
		}
	//	sort(L.begin(),L.end(),greater<int>());
	
		for(int i=1;i<=k;i++)//k个人 
		{
			//保证每一个人都要取到一个筷子
			dp[i][i*3] = dp[i-1][i*3-2] + (L[i*3-1] - L[i*3]) * (L[i*3-1] - L[i*3]);
			for(int j=i*3+1;j<=n;j++)//n个筷子 
			{
				 //j=3*i,也就是这时候一次性给你3根，然后你用后两个小的比较，前面一个大的就默认选择，
				//如果是从小到大会有错误，因为新来的一支是最大的，一定能取到，就是C，但是如果从大到小取到的就是最小的 
				//保证符合i对筷子都有一支最大的条件 
				dp[i][j] = min(dp[i][j-1],dp[i-1][j-2] + (L[j-1]-L[j]) * (L[j-1]-L[j]));	
			}
		}
		cout<<dp[k][n]<<endl;
		L.clear(); 

	}
   	    return 0;
}