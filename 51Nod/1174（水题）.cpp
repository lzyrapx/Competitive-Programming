#include <bits/stdc++.h>
using namespace std;
int a[12345];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int m;
	cin>>m;
	while(m--)
	{
		int l,r; int ans =0;
		cin>>l>>r; 
		for(int i=l;i<=r;i++)ans=max(ans,a[i]);
		cout<<ans<<endl;
	}
	return 0;
}