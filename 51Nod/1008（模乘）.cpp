#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	long long ans=1;
	for(int i=2;i<=n;i++){
		ans=ans*i%p;
	}
	printf("%lld\n",ans);
	return 0;
}