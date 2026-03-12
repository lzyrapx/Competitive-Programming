#include<bits/stdc++.h>
using namespace std;
int c[123456];
int t[123456];
int mx=0,mn=12345;
const double eps = 1e-14;
int n,T;
double calc(double x)
{
	double res = 0;
	for(int i=0;i<n;i++)
	{
		res += (double)c[i]*(t[i]-x)/(x-T); 
	}
//	cout<<"res="<<res<<endl; 
	return res;
}
int main()
{
	cin>>n;
	int C;
	cin>>T>>C;
	for(int i=0;i<=n-1;i++){
		cin>>t[i]>>c[i];
		mx = max(t[i],mx);
		mn = min(t[i],mn);
	}
	if(mn==mx)printf("Possible\n%.4f\n",(double)mn);
	else if(T>mx)
	{
		double l = mx ,r = T;
		for(int i=0;i<300;i++)
		{
			double mid = (l+r)/2;
			if(calc(mid)<=C) l = mid;
			else r = mid; 
		}
		if(calc(l)<=C)printf("Possible\n%.4f\n",(double)l);
		else puts("Impossible");
	}
	else if(T<mn)
	{
		if(calc(mn)<=C)printf("Possible\n%.4f\n",(double)mn);
		else puts("Impossible");
	}
	else puts("Impossible");
	
	return 0;
}