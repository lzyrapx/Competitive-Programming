#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
		ll a,b,c,k;
		cin>>a>>b>>c>>k;
		if(c % __gcd(b, __gcd(a,k-1))){
			puts("No");
		}
		else{
			puts("Yes");
		}
	}
	return 0;
} 