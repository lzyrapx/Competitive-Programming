#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t ;
	cin>>t;
	ll a,b;
	while(t--)
	{
		scanf("%lld%lld",&a,&b);//不AC就上输入挂吧 
		if(abs(a)==4611686018427387904 &&abs(b)==4611686018427387904&&a!=b)
		{
			cout<<"9223372036854775808"<<endl;
		}
		else
		{
			cout<<abs(a-b)<<endl;
		}
	}
	return 0;
	
}