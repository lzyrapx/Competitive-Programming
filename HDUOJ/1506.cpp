#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll a[100005],Left[100005],Right[100005];
ll Max;
int main()
{
	int t;
	int n;
	while(cin>>n,n)
	{
		for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
		Left[1]=1;
		Right[n]=n;
		//求每个点左边连续比它大的最左边的下标，保存在Left[]数组里
		for(int i=2;i<=n;i++)
		{
			t=i;
			while(t>1 && a[i]<=a[t-1]) t=Left[t-1];
			Left[i]=t;
		}
		//求每个点右边连续比它大的最右边的下标，保存在Right[]数组里
		for(int i=n-1;i>=1;--i)
		{
			t=i;
			while(t<n && a[i]<=a[t+1]) t=Right[t+1];
			Right[i]=t;
		}
		Max=0;
		for(int i=1;i<=n;i++)
		{
			if((Right[i]-Left[i]+1)*a[i]>Max) Max=(Right[i]-Left[i]+1)*a[i];
		}
		cout<<Max<<endl;
	}
	return 0;
}