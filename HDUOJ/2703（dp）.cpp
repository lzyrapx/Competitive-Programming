/*
题意:有N条通路以及M个人，每条通路每次仅能通过w个人，每一组人通过需要花费时间t，
     且需要满足2个条件
 1.每次只能有一组人进入一条通路
 2.当通路入口有人且通路为空则必须进入
*/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int dp[25][2345];
int p[25],sec[25];
//dp[i][j]中表示当前进行处理的第 i 条通道，j为时间，保存该通道的路口有多少个人 
int DP()
{
	int ans = 0;
	int t = 0;
	for(int i=0;i<n;i++)//枚举 n 条通道 
	{
		for(int j=0;;j++) 
		{
			if(j>=1){
				dp[i][j]+=dp[i][j-1];
			}
			//当 j>ans时表示所有人已经从i-1条道路离开,
			//且 dp[i][j]=0, 表示所有人也从第 i条通道离开，就可以继续进行下一条通道的处理 
			if(j > ans && dp[i][j] == 0)break; 
			// t保存的是当前通道中的人离开道路的时间
			if(t!=0) t--; 
			// t=0时进行状态转移 
			else if(dp[i][j]!=0&&t==0)
			{
				dp[i+1][j+sec[i]] += min(dp[i][j],p[i]);
				dp[i][j] -= min(dp[i][j],p[i]);
				t = sec[i] - 1;
				ans = max(ans,j+sec[i]);	//ans保存的是所有人从 i-1条通道离开的时间		
			}
		 } 
	}
	return ans;
}
int main()
{
	while(true)
	{
		cin>>n>>m;//n条通道，m个人 
		if(n==0&&m==0)break;
		n = -n;
		for(int i=0;i<n;i++){
			cin>>p[i]>>sec[i];//容量 p 和通过时间 sec 
		}
		memset(dp,0,sizeof dp);
		dp[0][0] = m;
		int ans = DP();
		cout<<ans<<endl;
	}
	return 0;	
} 