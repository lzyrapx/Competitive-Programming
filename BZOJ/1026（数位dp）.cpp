#include<bits/stdc++.h>
using namespace std;
int a,b;
int dp[10][10][2];
int vis[10][10][2];
int dig[10];
int dfs(int pos, int pre, int less)
{
	if(pos<0)return 1; //只有一位数，看样例是满足的 
	else if(pre>=0 && vis[pos][pre][less]) return dp[pos][pre][less];
	else
	{
		int ans=0;
		if(pre== -1){
			ans+=dfs(pos-1,-1,less||dig[pos]>0);//0
			if(less==0){
				for(int i=1; i <= dig[pos]; i++)
					ans+=dfs(pos-1, i, i < dig[pos]);//1-9
		 	}
			else{
				for(int i=1;i<=9;i++)
					ans+=dfs(pos-1, i, 1);//1-9
		 	}
		}  
		
		else{
			if(less==1){
				for(int i=0;i<10;i++)//0-9
					if(abs(i-pre)>1){
						ans+=dfs(pos-1, i, 1);
					}
			}
			else {
				for(int i=0;i<10;i++)//0-9
					if( i <= dig[pos] && abs(i-pre) > 1 )
						ans+=dfs(pos-1, i , i< dig[pos] );
			} 			 
	   }
	   
	   if(pre>=0){
	   	vis[pos][pre][less] = 1, dp[pos][pre][less] = ans;
	   }
	   return ans;		
	} 	
}
int main()
{
	
	while(~scanf("%d %d",&a,&b))
	{
		a--;
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		int len1=0,len2=0;
		int ans1=0,ans2=0;
		while(a) dig[len1++] =a%10,a/=10;
		ans1=dfs(len1-1, -1, 0);
		while(b) dig[len2++] =b%10,b/=10;
		ans2=dfs(len2-1, -1, 0);
		printf("%d\n",ans2-ans1);
	}
	
	return 0;
}