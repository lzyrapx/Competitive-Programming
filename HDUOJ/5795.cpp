#include<bits/stdc++.h>
using namespace std;
int SG(int x)
{
	if(x%8==0)return x-1;
	if(x%8==7)return x+1;
	return x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int ans=0;
		int a=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			ans ^= SG(a);
		}
		if(!ans)puts("Second player wins.");
		else puts("First player wins.");
    }
	return 0;
}