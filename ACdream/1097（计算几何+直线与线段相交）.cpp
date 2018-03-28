/*
* this code is made by LzyRapx
* Problem: 1097
* Verdict: Accepted
* Submission Date: 2017-07-23 02:09:01
* Time: 824MS
* Memory: 1676KB
*/
#include<bits/stdc++.h>
 
using namespace std;
 
const double eps = 1e-12 ;
double add(double a, double b)
{
    return (fabs(a + b) < eps * (fabs(a) + fabs(b))) ? 0 : (a + b);
}
  
struct Point
{
    double x, y;
    Point(){}
    Point(double x, double y):x(x),y(y){}
    double operator ^(Point a)
    {
        return add(x * a.y ,- y * a.x );
    }
    Point operator - (Point a){
        return Point(add(x ,- a.x) , add(y ,- a.y)) ;
    }
    void read(){
        scanf("%lf%lf" , &x ,&y) ;
    }
};
  
struct Line
{
    Point st, ed;
    Line(){}
    Line(Point st, Point ed):st(st),ed(ed){}
    bool intersection(Line l)
    {
       double d1  = (ed -st)^(l.st - st) , d2 = (ed - st)^(l.ed - st) ;
       return d1 * d2 <= 0 ;
    }
};
  
const int maxn = 55 ;
Point dot[maxn*4] ;
Line line[maxn] ;
int n;
int solve()
{
       int tmp,ans = 0;
       for(int i = 1 ; i <= 2*n;i++)
       {
          for(int j = i+1 ; j <= 2*n ; j++)
          {
               tmp = 0 ;
               Line now = Line(dot[i] , dot[j]) ;
               for(int k = 1 ; k <= n ; k++)
               {
                   tmp += now.intersection(line[k]) ;
               }
               ans = max(ans , tmp)  ;
          }
       }
       return ans;
}
  
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1 ; i <= n ; i++)
        {
           scanf("%lf%lf%lf%lf" ,&dot[i].x , &dot[i].y , &dot[i+n].x , &dot[i+n].y) ;
           line[i] = Line(dot[i] , dot[i+n]) ;
        }
        cout<<solve()<<endl;
    }
    return 0;
}