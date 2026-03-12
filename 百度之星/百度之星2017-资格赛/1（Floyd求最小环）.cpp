#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define inf 1044266558
typedef struct Point
{
	int x, y;
	Point operator - ( const Point &b ) const
	{
		Point c;
		c.x = x-b.x; c.y = y-b.y;
		return c;
	}
	double operator * ( const Point &b ) const
	{
		return x*b.y-y*b.x;
	}
}Point;
Point h[505], s[505];
int n, m, ans, road[505][505];
bool Jud(Point x, Point y, Point z)
{
	if((x.x<z.x && y.x<z.x) || (x.y<z.y && y.y<z.y) || (x.x>z.x && y.x>z.x) || (x.y>z.y && y.y>z.y))
		return 1;
	return 0;
}
int main(void)
{
	int i, j, k, flag;
	while(scanf("%d", &n)!=EOF)
	{
		memset(road, 62, sizeof(road));
		for(i=1;i<=n;i++)
			scanf("%d%d", &h[i].x, &h[i].y);
		scanf("%d", &m);
		for(i=1;i<=m;i++)
			scanf("%d%d", &s[i].x, &s[i].y);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=m;j++)
			{
				flag = 1;
				for(k=1;k<=n;k++)
				{
					if((s[i]-s[j])*(s[i]-h[k])<0 || (s[i]-s[j])*(s[i]-h[k])==0 && Jud(s[i], s[j], h[k]))
					{
						flag = 0;
						break;
					}
				}
				if(flag)
					road[i][j] = 1;
			}
		}
		ans = inf;
		for(k=1;k<=m;k++)
		{
			for(i=1;i<=m;i++)
			{
				if(road[i][k]==inf)
					continue;
				for(j=1;j<=m;j++)
					road[i][j] = min(road[i][j], road[i][k]+road[k][j]);
			}
		}
		for(i=1;i<=m;i++)
			ans = min(ans, road[i][i]);
		if(ans>m)
			printf("ToT\n");
		else
			printf("%d\n", m-ans);
	}
	return 0;	
}