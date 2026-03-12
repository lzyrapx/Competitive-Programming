#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{	
		int ans;
		ans=a+b-(__gcd(a,b));
		cout<<ans<<endl;
	}
}