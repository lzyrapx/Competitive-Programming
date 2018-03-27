#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct point
{
	double x,y;
}a[100001];
bool compare1(const point &a,const point &b)
{
	if(fabs(a.x-b.x)<1e-8)
        return a.y < b.y;
    return a.x<b.x;

}
bool compare2(const point &a,const point &b)
{
	if(fabs(a.y-b.y)<1e-8)
        return a.x < b.x;
    return a.y<b.y;

}

int main()
{
	int n;
	double k,s;
	while(~scanf("%d\n",&n)&&n)
	{
		k=11111111;
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&a[i].x,&a[i].y);
		}
		sort(a,a+n,compare1);
		for(int i=0;i<n-1;i++)
		{
			s=sqrt((a[i].x-a[i+1].x)*(a[i].x-a[i+1].x)+(a[i].y-a[i+1].y)*(a[i].y-a[i+1].y));
				if(k>s)
				k=s;
		}
		sort(a,a+n,compare2);
		for(int i=0;i<n-1;i++)
			{
				s=sqrt((a[i].x-a[i+1].x)*(a[i].x-a[i+1].x)+(a[i].y-a[i+1].y)*(a[i].y-a[i+1].y));
				if(k>s)
				k=s;
			}
       printf("%.2lf\n",k/2);

	}
	return 0;
}