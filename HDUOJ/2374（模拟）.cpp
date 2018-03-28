#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
long long a[1234];
int main()
{
	int n;
	while(cin>>n)
	{
		ans = 0;
		if(n==0)break;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>0;--i){
			
			ans+=a[i];
			for(int j=i-1;j>0;--j)
			{
				a[j]+=a[i];
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}