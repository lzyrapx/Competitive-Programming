#include <bits/stdc++.h>
using namespace std;
int t, a, b;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a>b)swap(a,b);
		int k=(int)(b - a) * (1 + sqrt(5)) * 0.5;
		if(a==k)puts("B");
		else puts("A");
	}
	return 0;
}
