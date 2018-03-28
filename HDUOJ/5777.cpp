#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100010];
bool vis[100010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		n--;
		sort(a+1,a+n+1);
		long long sum=0;
		//n++; 
		for(int i=1; i<= n; i++) //Ã¶¾Ù¾àÀë 
		{
			sum+=a[i];
			if(i>n-k+1)
			sum-=a[i];
		} 
		sum=sum+n+1;
		printf("%I64d\n",sum); 
		
	}
	return 0;
}