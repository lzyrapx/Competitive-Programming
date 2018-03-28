#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll val[123];
ll sum[123];
ll solve(ll a, ll b, ll c)  
{  
    return (a+b+c) - max(a,max(b,c)) - min(a,min(b,c));  
}  
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++) cin>>val[i];
		sum[0] = 0;
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+val[i];
		
		ll ans = 0;
		//第一刀
		for(int i=1;i<=n-1;i++)
		{
			ll three = 0;
			ll two = 0;
			//第二刀枚举的时候应该在第一刀的左右都要枚举 
			for(int j = i+1;j<=n-1;j++)//后面扫一遍 
			{
				if(i==j)continue;
				ll tmp1 = sum[i];
				ll tmp2 = sum[j] -sum[i];
				ll tmp3 = sum[n] - sum[j];
				ll x = solve(tmp1,tmp2,tmp3);//中间大小那个 
				ll Min = min(tmp1,min(tmp2,tmp3));
				
				if(x > two) {
					three = Min;
					two = x;
				}
				else if(x == two && Min < three){
					three = Min;
				}
			}
			
			for(int j=1;j<=i;j++)//前面的扫一遍 
			{
				if(i==j)continue;
				ll tmp1 = sum[j];
				ll tmp2 = sum[i] - sum[j];
				ll tmp3 = sum[n] - sum[i];
				ll x = solve(tmp1,tmp2,tmp3);
				ll Min = min(tmp1,min(tmp2,tmp3));
				
				if(x > two) {
					three = Min;
					two = x;
				}
				else if(x==two && Min < three){
					three = Min;
				}
			}
			ans = max(ans,three);
		}
		cout<<ans<<endl; 
	}
	return 0;
}