#include <bits/stdc++.h>
using namespace std;;

int main()
{
	long long n;
	while(cin>>n)
	{
		//cout<<abs(n)<<endl;
		long long ans = 0 ;
		while(n)
		{
			ans += n%10;
			n/=10;
		}
		cout<<abs(ans)<<endl;
	}
	return 0;
}