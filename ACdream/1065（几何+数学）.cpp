/*
* this code is made by LzyRapx
* Problem: 1065
* Verdict: Accepted
* Submission Date: 2017-07-15 23:58:36
* Time: 24MS
* Memory: 1776KB
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi acos(-1.0)
int main()
{
    //printf("%.10lf\n",pi);
    int t;
    double n,a;
    cin>>t;
    while(t--)
    {
        scanf("%lf%lf",&n,&a);
        if(a>=90) a-=90;
        if(a==0)
        {
            printf("%.2lf\n",n*n);continue;
        }
        a = a*pi/180.0;
        double r = n / (1+cos(a)+sin(a));
        printf("%.2lf\n",n*n-r*r*(sin(2*a)));
    }
    return 0;
}