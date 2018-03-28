/*
* this code is made by LzyRapx
* Problem: 1012
* Verdict: Accepted
* Submission Date: 2017-06-05 13:27:35
* Time: 0MS
* Memory: 1776KB
*/
#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
int main()
{
    double d,angle;
    int n;
    while(cin>>n>>d)
    {
        double sum  = 0;
        for ( int i = 0; i < n; i++)
        {
            cin>>angle;
            sum += 0.5*d*d*sin(angle*PI/180.0);
        }
        printf("%.3lf\n",sum); 
    }
    return 0;
}