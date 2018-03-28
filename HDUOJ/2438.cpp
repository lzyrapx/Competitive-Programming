#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstring>
//const double Min=1e-7;
using namespace std;
double x,y,l,d;
double solve(double a)
{
     return (-x+l*sin(a)+d/cos(a))/tan(a);
 }
int main()
{
    
    while(~scanf("%lf%lf%lf%lf",&x,&y,&l,&d))
    {
        //90度换成弧度就是pi/2
        double low=0,high=acos(-1.0)/2.0;
        double mid,mmid;
        if(x<d || y<d)
        {
            puts("no");continue;
        }
        while(high-low>1e-8)
        {
            mid=(low+high)/2.0;
            mmid=(mid+high)/2.0;
            if(solve(mid)>solve(mmid))
            high=mmid;
            else low=mid;
        }
        if(solve(mid)<y)
        {
            puts("yes");
        }
        else puts("no");
    }
    return 0;
}