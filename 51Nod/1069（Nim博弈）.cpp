#include<bits/stdc++.h>
using namespace std;
const double Pi=3.1415926;

int main()
{
	int t;
	cin>>t;
	int ans=0;
	while(t--)
	{
		int n,k;
		cin>>n;
		ans^=n;
	}
	if(ans)puts("A");
	else puts("B");
	return 0;
}