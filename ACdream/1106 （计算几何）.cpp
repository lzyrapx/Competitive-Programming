/*
* this code is made by LzyRapx
* Problem: 1106
* Verdict: Accepted
* Submission Date: 2017-06-21 20:11:16
* Time: 4MS
* Memory: 3244KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+10;
const int N=50000;
const double eps=1e-9;
const double INF=1e99;
   
struct Point
{
    double x,y;
};
   
Point P[N],Q[N];
//点积 
double cross(Point A,Point B,Point C)
{
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
   
double dist(Point A,Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
//叉积 
double multi(Point A,Point B,Point C)
{
    return (B.x-A.x)*(C.x-A.x)+(B.y-A.y)*(C.y-A.y);
}
   
//顺时针排序
void anticlockwise(Point p[],int n)
{
    for(int i=0;i<n-2;i++)
    {
        double tmp=cross(p[i],p[i+1],p[i+2]);
        if(tmp>eps) return;
        else if(tmp<-eps)
        {
            reverse(p,p+n);
            return;
        }
    }
}
   
//计算C点到直线AB的最短距离
double Getdist(Point A,Point B,Point C)
{
    if(dist(A,B)<eps) return dist(B,C);
    if(multi(A,B,C)<-eps) return dist(A,C);
    if(multi(B,A,C)<-eps) return dist(B,C);
    return fabs(cross(A,B,C)/dist(A,B));
}
   
//求一条直线的两端点到另外一条直线的距离，反过来一样，共4种情况
double MinDist(Point A,Point B,Point C,Point D)
{
    return min( min(Getdist(A,B,C), Getdist(A,B,D)), min( Getdist(C,D,A), Getdist(C,D,B)));
}
   
double solve(Point P[],Point Q[],int n,int m)
{
    int yminP=0,ymaxQ=0;
    for(int i=0;i<n;i++)
    {
         if(P[i].y < P[yminP].y)
         {
            yminP = i;
         }
            
    }      
    for(int i=0;i<m;i++)
    {
        if(Q[i].y > Q[ymaxQ].y)
        {
            ymaxQ = i;
        }
            
    }       
    P[n]=P[0];
    Q[m]=Q[0];
    double tmp,ans=INF;
    for(int i = 0; i < n; i++)
    {
        while(tmp = cross( P[yminP + 1],Q[ymaxQ + 1],P[yminP]) - cross( P[yminP + 1], Q[ymaxQ], P[yminP] ) > eps )
        {
            ymaxQ = (ymaxQ + 1)%m;
        }
              
        if(tmp < -eps) 
        {
            ans=min(ans,Getdist( P[yminP],P[yminP + 1],Q[ymaxQ] ) );
        }
        else
        {
            ans=min(ans,MinDist(P[yminP],P[yminP + 1],Q[ymaxQ],Q[ymaxQ + 1]));
        }         
        yminP = (yminP + 1 )%n;
    }
    return ans;
}
   
int main()
{
    int n,m;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin >> P[i].x >> P[i].y;
    }    
    cin >> m;
    for(int i = 0; i < m ; i++){
        cin >> Q[i].x >> Q[i].y;
    }
    anticlockwise(P,n);
    anticlockwise(Q,m);
    double ans = min( solve(P,Q,n,m), solve(Q,P,m,n));
    printf("%.4f\n",ans);
    return 0;
}