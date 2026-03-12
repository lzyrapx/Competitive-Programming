#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;

typedef struct point
{
    int x,y;
}point;
point a[100];
double area(point p,point q)
{
    return p.x * q.y - q.x * p.y;
}
int main()
{
    int i,n;
    double sum;
    while(scanf("%d ",&n) != EOF && n)
    {
        for(i=0;i<n;i++)
            scanf("%d %d",&a[i].x,&a[i].y);
            sum = area(a[n-1],a[0]);
            for(i=1;i<n;i++)
                sum +=area(a[i-1] ,a[i]);
            printf("%.1f\n",0.5 * sum);
    }
    return 0;
}