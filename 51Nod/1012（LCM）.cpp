#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a,b;
	cin>>a>>b;
	cout<<(a/(__gcd(a,b))*b)<<endl;
	return 0;
}