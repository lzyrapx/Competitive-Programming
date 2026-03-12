#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&m,&n);
		if(__gcd(m,n)==1)puts("NO");//最大公约数大于1，中间一定有空余的洞没有走
		else puts("YES");
	}
	return 0;
}