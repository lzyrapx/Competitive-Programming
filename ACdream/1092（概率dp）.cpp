/*
* this code is made by LzyRapx
* Problem: 1092
* Verdict: Accepted
* Submission Date: 2017-07-28 13:50:25
* Time: 336MS
* Memory: 1716KB
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,t;
    double p;
} a[1009];
double dp[1009];
 
int cmp(node xx,node yy)
{
    return xx.t<yy.t;
}
int main()
{
    int t,n,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&v);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d %lf",&a[i].x,&a[i].y,&a[i].t,&a[i].p);
        }
             
        sort(a,a+n,cmp);
        memset(dp,0,sizeof (dp));
        double ans=0;
        for(int i=0; i<n; i++)
        {
            dp[i]=a[i].p;
            for(int j=0; j<i; j++)
            {
                if(v*(a[i].t-a[j].t)>=sqrt(1.0*(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)))
                {
                    dp[i]=max(dp[i],dp[j]+a[i].p);
                }
                     
            }  
            ans=max(dp[i],ans);
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}