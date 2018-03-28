#include<bits/stdc++.h>
using namespace std;
int a[510];
int ans[1010];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans[__gcd(a[i],a[j])]=1;
			}
		}
		int flag =1, cnt=1; // flag 标志是否有新的gcd产生 
		while(flag && cnt<=n-3)
		{
			cnt++;
			flag=0;
			//将之前求出的gcd再gcd 
			for(int i=1;i<=1000;i++){
					for(int j=1;j<=n;j++){
						int temp=__gcd(a[j],i);
						if(ans[i] && ans[temp]==0){
							flag=1;
							ans[temp]=1;
						}
					}
			}
		}
		
		flag=1;
		for(int i=1;i<=1000;i++){		
			if(ans[i]){
				if(flag){
					cout<<i;
				    flag=0;
				}
				else cout<<" "<<i;
			}
			
		}
		cout<<endl;
	}
	return 0;
}