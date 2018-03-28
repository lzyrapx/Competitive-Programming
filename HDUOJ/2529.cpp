#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    double h, l ,v;
    while(cin>>h>>l>>v && (h || l || v))
    {
        double s = -9.8*l*l/(2*v*v) - l*l/(2.0*(-9.8*l*l)/(v*v)) + h;
        printf("%.2lf\n",s);
    }
}

