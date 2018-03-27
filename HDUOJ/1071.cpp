#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    double x1,x2,x3,y1,y2,y3,a,b,c,k,t,x,s1,s2;
    cin>>T;
    while(T--)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        
        a=(y2-y1)/((x1-x2)*(x1-x2));
        
        b=-2*a*x1;
        
        c=y1+a*x1*x1;
        
        k=(y3-y2)/(x3-x2);
        
        t=y3-(k*x3);
        
        s1=a/3*x3*x3*x3+(b-k)/2*x3*x3+(c-t)*x3;
        s2=a/3*x2*x2*x2+(b-k)/2*x2*x2+(c-t)*x2;
        
        printf("%.2lf\n",s1-s2);
    }
    return 0;
}
