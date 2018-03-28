/*
* this code is made by LzyRapx
* Problem: 1094
* Verdict: Accepted
* Submission Date: 2017-07-28 17:25:10
* Time: 20MS
* Memory: 1892KB
*/
#include<bits/stdc++.h>
using namespace std;
#define eps 1e-6
#define pi acos(-1)
struct Point
{
    double x,y;
    Point(double a=0,double b=0)
    {
        x=a,y=b;
    }
    Point operator -(Point a){
        return Point(x-a.x,y-a.y);
    }
    double operator *(Point a){
        return x*a.x+y*a.y;
    }
     Point operator+(Point b)
    {
        return Point(x+b.x,y+b.y);
    }
    double dis(Point b)
    {
        return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
    }
}p[5];
 
double dis(Point a,Point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
double ang(Point a,Point b, Point c)
{
    Point d,e;
    d=b-a;
    e=c-a;
    return acos(d*e/(dis(a,b)*dis(a,c)));
}
 
Point wx(Point a,Point b,Point c)//外心
{
    double aaa=tan(ang(a,b,c)),bbb=tan(ang(b,c,a)),ccc=tan(ang(c,b,a));
    double aa=bbb+ccc,bb=aaa+ccc,cc=aaa+bbb,p=aa+bb+cc;
    return Point((aa*a.x+bb*b.x+cc*c.x)/p,(aa*a.y+bb*b.y+cc*c.y)/p);
}
 
double angle(Point a, Point b, Point c)
{
    Point d,e;
    d=b-a,e=c-a;
    return acos(d*e/(Point().dis(d)*Point().dis(e)));
}
 
Point G(Point a, Point b, Point c)//重心
{
    return Point((a.x+b.x+c.x)/3,(a.y+b.y+c.y)/3);
}
 
Point I(Point a,Point b,Point c)//内心
{
    double aa=b.dis(c),bb=c.dis(a),cc=a.dis(b),p=aa+bb+cc;
    return Point((aa*a.x+bb*b.x+cc*c.x)/p,(aa*a.y+bb*b.y+cc*c.y)/p);
}
 
Point H(Point a,Point b,Point c)//垂心
{
    double aa=tan(angle(a,b,c)),bb=tan(angle(b,c,a)),cc=tan(angle(c,b,a)),p=aa+bb+cc;
    return Point((aa*a.x+bb*b.x+cc*c.x)/p,(aa*a.y+bb*b.y+cc*c.y)/p);
}
 
Point Ia(Point a,Point b,Point c)//A点对应的旁心
{
    double aa=-b.dis(c),bb=c.dis(a),cc=a.dis(b),p=aa+bb+cc;
    return Point((aa*a.x+bb*b.x+cc*c.x)/p,(aa*a.y+bb*b.y+cc*c.y)/p);
}
Point Ib(Point a,Point b,Point c)//B点对应的旁心
{
    double aa=b.dis(c),bb=-c.dis(a),cc=a.dis(b),p=aa+bb+cc;
    return Point((aa*a.x+bb*b.x+cc*c.x)/p,(aa*a.y+bb*b.y+cc*c.y)/p);
}
Point Ic(Point a,Point b,Point c)//C点对应的旁心
{
    double aa=b.dis(c),bb=c.dis(a),cc=-a.dis(b),p=aa+bb+cc;
    return Point((aa*a.x+bb*b.x+cc*c.x)/p,(aa*a.y+bb*b.y+cc*c.y)/p);
}
 
bool is_ok(int n,double ang){
    double s=n*ang/pi;
    if(fabs(s-floor(s+0.50))<eps) return true;
    else return false;
}
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<3;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }    
        double A=ang(p[0],p[1],p[2]);
        double B=ang(p[1],p[0],p[2]);
        double C=ang(p[2],p[1],p[0]);
         
        Point o=wx(p[0],p[1],p[2]); //外心 
         
        if(fabs(o.x)<eps) o.x=0.00;
        if(fabs(o.y)<eps) o.y=0.00;//此处防止出现-0.000的情况
         
        printf("%.4f %.4f ",o.x,o.y);
        for(int n=3;;n++)
        {   
            if(is_ok(n,A) && is_ok(n,B) && is_ok(n,C)){
                printf("%d\n",n);
                break;
            }
        }
    }
    return 0;
}