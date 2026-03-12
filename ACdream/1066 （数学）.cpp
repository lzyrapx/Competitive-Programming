/*
* this code is made by LzyRapx
* Problem: 1066
* Verdict: Accepted
* Submission Date: 2017-06-07 16:42:05
* Time: 0MS
* Memory: 1760KB
*/
#include <bits/stdc++.h>
using namespace std;
double a[12345];
double x,ans,sum;
int main()
{
    int n;
    while(cin>>n)
    {
        sum = 1;
        cin>>a[0];
        for(int i=1;i<n;i++){
            cin>>a[i];
            sum += a[0]/a[i];
        }
        sum = 1.0 / sum;
        cin>>x;
        ans = sum*a[0]*x;
        printf("%.2f\n",ans);
    }
    return 0;
}