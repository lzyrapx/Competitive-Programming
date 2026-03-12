#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010;
ll dig[20];
//考虑当前的第 i 位，上一位是奇(1)偶(0)性为 j ，已经连续 k位 ，考虑有没有前导零 
ll dp[21][2][21];
ll dfs(ll now_pos,int parity = 0,int contius = 0,int flag=1, int first_0=1)
{
	if(now_pos==0){
		if(parity==1 && (contius&1)) return 0;
		else if(parity==1 && (contius&1)==0)return 1;
		else if(parity==0 && (contius&1) ) return 1;
		else return 0; 
	}
	//已经搜索过了 
	if(flag==0 && dp[now_pos][parity][contius] != -1 )
		return dp[now_pos][parity][contius];
		
	int n = flag ? dig[now_pos] : 9;
	ll ans =0; 
	for(int i=0;i<=n;i++)
	{
		if(i&1)//奇数 
		{
			if(first_0){ //有前导 0 
				if(i==0) ans+=dfs(now_pos-1,0,0,flag&&i==n, 1);
				else ans+=dfs(now_pos-1,1,1,flag&&i==n,0);
			}
			
		    else if(parity==0)//上一位是偶数
			{
				//连续奇数位 
				if(contius&1) ans+=dfs(now_pos-1,1,1,flag&&i==n,first_0);
			}
			else if(parity==1) //上一位是奇数 
			{
				ans+=dfs(now_pos-1,1,contius+1,flag&&i==n,first_0);
			}
		}
		else
		{
			if(first_0)
			{
				if(i==0) ans+=dfs(now_pos-1,0,0,flag&&i==n, 1);
				else ans+=dfs(now_pos-1,0,1,flag&&i==n, 0);
			}
			
			else if(parity==0){
				ans+=dfs(now_pos-1,0,contius+1,flag&&i==n,first_0);
			}
			else if(parity==1){
				if((contius&1)==0) 
				ans+=dfs(now_pos-1,0,1,flag&&i==n,first_0); 
			} 
		 } 
	}
	if(flag==0) dp[now_pos][parity][contius] = ans;
	return ans;
}
int main()
{
	int t;
	int cas=1;
	ll l ,r;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		memset(dig,0,sizeof(dig));
		ll ans1=0,ans2=0;
		ll len1=0,len2=0;
		scanf("%I64d%I64d",&l,&r),l--;
		for( len1=0; l ; l/=10) dig[++len1]=l%10;
		 ans1=dfs(len1);
		for( len2 = 0; r; r/=10) dig[++len2]=r%10;
		 ans2=dfs(len2);
		printf("Case #%d: %I64d\n",cas++, ans2 - ans1);
	}
	return 0;
}
