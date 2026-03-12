
#include<stdio.h>
#include<cmath>
#include<iostream>
using namespace std;
struct zhi
{
	double x,y;
};
double dist(zhi a,zhi b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dist1(zhi a)
{
	return sqrt((a.x)*(a.x)+(a.y)*(a.y));
}
int main()
{
	int t;
	zhi a,b;
	scanf("%d",&t);
	while(t--)
	{
		cin>>a.x>>a.y>>b.x>>b.y;	
		double d1=dist1(a);
		double d2=dist1(b);
		double d3=dist(a,b);
		//cout<<d1<<endl<<d2<<endl<<d3;
		double ans=0;
		ans=(acos((d3*d3-d1*d1-d2*d2)/(2*d1*d2))/acos(-1.0)*180);
		ans=fabs(ans-180);
		printf("%.2lf\n",ans);
	}
	return 0;
}