#include<bits/stdc++.h>
using namespace std;
const double Pi=3.1415926;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(n%(k+1))puts("A");
		else puts("B");
	}
	return 0;
}