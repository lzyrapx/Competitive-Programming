#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

#define INF 0x3ffffff
struct point
{
	double x,y;
};
point p[105];
int n;
double ans;
double map[105][105];

void prim()
{
	double dis[105];
	double min;
	int k;
	dis[1]=0;
	for(int j=2;j<=n;j++)
	{
		dis[j]=map[1][j]; //其他点的距离 
	}
	for(int i=2;i<=n;i++) //找其他n条边 
	{
		min=INF;
		for(int j=1;j<=n;j++) 
		{
			if(dis[j]<min && dis[j]) //有可能重复 ,标志 
			{
				min=dis[j];
				k=j;
			}  				
		}
	    ans+=min; 
		dis[k]=0;
		for(int j=1;j<=n;j++)
		{
			if(map[k][j]< dis[j] && dis[j]) 
			  dis[j]=map[k][j];

		 } 
	}
}
int main()
{

	while(~scanf("%d",&n))
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf %lf",&p[i].x,&p[i].y);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)map[i][j]=INF;
				else map[i][j]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));

			}
		}
		prim();
		printf("%.2f\n",ans);
	}
	return 0;
}