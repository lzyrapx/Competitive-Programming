#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,k;
	int ans = 0;
	cin>>n>>k;
	for(int i=2;i<=n;i++)
	{
		ans=(ans+k)%i;
	}
	cout<<ans+1<<endl;
	return 0;
}