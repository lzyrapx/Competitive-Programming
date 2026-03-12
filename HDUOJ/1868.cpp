#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		long long m=2*n,x;
		long long sq=(long long)sqrt(m);
		int ans=0;
		for(long long i=2;i<=sq;i++)
		{
			x=(long long)( n/1.0/i - (i-1)/2 );
			if((x+x+i-1)*i==m)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}