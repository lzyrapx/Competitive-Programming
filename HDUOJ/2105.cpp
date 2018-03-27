#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n)
	{
	   while(n--)
	  {
		double x1,x2,x3,y1,y2,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		printf("%.1lf %.1lf\n",1.0*(x1+x2+x3)/3,1.0*(y1+y2+y3)/3);
	  }
  }
  return 0;
}
