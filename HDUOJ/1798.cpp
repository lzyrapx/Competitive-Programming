#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

struct circle
{
  double x,y,r;
};
double dist(circle a,circle b)
{
  return (double)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	circle a,b;
	double dis,p,area,a1,a2;
	double  s1,s2,s3;
	while(cin>>a.x>>a.y>>a.r>>b.x>>b.y>>b.r)
	{
		dis=dist(a,b);
		double R=min(a.r,b.r);
		
		if(dis<=abs(a.r-b.r)) //内含或内切
		area=acos(-1.0)*R*R; 
		else if(dis>=(a.r+b.r)) //外切或相离 
		area=0.0;
	else
	{
  	  double p=(a.r+b.r+dis)/2.0;
	  a1=acos((a.r*a.r+dis*dis-b.r*b.r)/(2.0*a.r*dis));
	  a2=acos((b.r*b.r+dis*dis-a.r*a.r)/(2.0*b.r*dis));
  	  s1=a1*a.r*a.r;
  	  s2=a2*b.r*b.r;
  	  s3=2*sqrt(p*(p-a.r)*(p-b.r)*(p-dis));
	
	  area=s1+s2-s3; 
	}
	printf("%.3lf\n",area);
  }
	return 0;
}