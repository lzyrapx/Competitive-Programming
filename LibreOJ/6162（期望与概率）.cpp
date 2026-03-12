#include<bits/stdc++.h>
using namespace std;
double c[1100],d[1100];
/*
因为我们要算期望，所以我们需要枚举第i个人在第j个位置需要的时间，
累加起来，又因为第i个人在第j个位置的概率一定为1/n，所以我们可以得到公式：
1/n* \sum{i=1~n}\sum{j=1~n} {u * n / ( c[i] - (j-1) * d[i] - v)}
*/ 
int main()
{
	int n;
	double u,v;
	scanf("%d%lf%lf",&n,&v,&u); 
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&c[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lf",&d[i]);
	}
	double ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{
			ans += u / ( c[i] - (j-1) * d[i] - v); 
		}
	}
	printf("%.3lf\n",ans);
	return 0;
 } 