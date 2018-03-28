/*
* this code is made by LzyRapx
* Problem: 1107
* Verdict: Accepted
* Submission Date: 2017-07-22 12:59:27
* Time: 0MS
* Memory: 1828KB
*/
#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct point 
{
    double x,y;
}tower,p[10010];
bool cmp(point p1,point p2)
{
    if(fabs(p1.x - p2.x) < eps) return p1.y < p2.y ? 1 : 0;
    return p1.x < p2.x ? 1 : 0;
}
int Is_same(point p1,point p2)
{
    if(fabs(p1.x - p2.x) > eps) return 0;
    if(fabs(p1.y - p2.y) > eps) return 0;
    return 1;
}
int main()
{
    int n;
    while(~scanf("%lf%lf",&tower.x,&tower.y))
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        int k = 0;
        sort(p,p+n,cmp);
        for(int j = 0;j < n;j++)
        {
            if(Is_same(tower,p[j]))continue;
            if(j > 0 && Is_same(p[j],p[j-1])) continue;
            p[k++] = p[j];
        }
        n = k;
        if(n==0){
            puts("Yes");
            continue;
        }
        double tmp = p[0].x - tower.x;
        bool flag = true;
        for(int i=1;i<n;i++)
        {
            if(tmp*(p[i].x - tower.x) < -eps)
            {
                flag = false;
            }
            if(fabs(p[i].x - p[i-1].x) < eps) 
            {
                flag = false;
            }
        }
        if(fabs(tmp) < eps && flag == false)
        {
            puts("No");
        }
        else if(n==1)
        {
            puts("Yes");
        }
        else
        {
            double a1=tower.x * tower.x;
            double a2=p[0].x * p[0].x;
            double a3=p[1].x * p[1].x;
             
            double b1=tower.x;
            double b2=p[0].x;
            double b3=p[1].x;
             
            double c1=tower.y;
            double c2=p[0].y;
            double c3=p[1].y;
             
            double a=((c1-c2)*(b2-b3)-(c2-c3)*(b1-b2))/((a1-a2)*(b2-b3)-(a2-a3)*(b1-b2));
            double b=((c1-c2)*(a2-a3)-(c2-c3)*(a1-a2))/((b1-b2)*(a2-a3)-(b2-b3)*(a1-a2));
            double c=c1 - a1 * a - b1 * b;
            if(a>-eps) 
            {
                puts("No");
            }
            else
            {
                for(int i=2;flag&&i<n;i++)
                {
                    tmp = a * p[i].x * p[i].x + b * p[i].x + c;
                    if(fabs(tmp - p[i].y) > eps) flag = false;
                }
                if(flag){
                    puts("Yes");
                }
                else
                {
                    puts("No");
                }
            }
        }
    }
    return 0;
}