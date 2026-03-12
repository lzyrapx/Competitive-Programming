#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10000010;
const int mod = 1e9+7;
int n;
ll x[1010],y[1010];
ll  r[1010],f[1010];
ll sqr(ll x)
{
	return x*x; 
}
ll ans;
/*
就是被包含偶数次的圆内为阴影, 被包含奇数次的圆为空白 
求将一个这幅图分成两幅, 如上面两张图, 问最大阴影面积是多少？

最优方法: 把所有没有被包含过的圆放在第一幅图, 其他圆放在第二幅图 
可以将第二幅图任何圆移到第一幅图上, 你会发现无论哪种情况, 
总面积都变小或不变(相对于最优方法)。 
*/ 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{ 
		cin>>x[i]>>y[i]>>r[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				if(sqr(x[i]-x[j]) + sqr(y[i]-y[j]) <= sqr(r[i]) && r[i] > r[j])
				{
					f[j]++;
				}
			}
		}
	}
	//for(int i=1;i<=n;i++)cout<<f[i]<<" ";cout<<endl; 
	for(int i=1;i<=n;i++)
	{
		if(!f[i] || f[i] % 2==1)
		{
			ans += sqr(r[i]);
		//	cout<<i<<endl;
		}
		else
		{
			ans -= sqr(r[i]);
		}
	}
	printf("%.9f\n",acos(-1)*ans);
	return 0;
}