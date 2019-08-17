#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
template<class T> inline bool ten(T &x,const T &y){return y<x?x=y,1:0;}
template<class T> inline bool rel(T &x,const T &y){return x<y?x=y,1:0;}
typedef long long LL;
const double pi=acosl(-1.0);
const int maxn=405;
int n,m;
int a[maxn];
LL ans;

double sx,sy;

struct point
{
    int x,y;
    point(){}
    point(const int &xx,const int &yy):x(xx),y(yy){}
    
    point operator+(const point &o)
    {return point(x+o.x,y+o.y);}
    
    bool operator<(const point &o)const
    {return x*sx+y*sy<o.x*sx+o.y*sy;}
    
    bool operator==(const point &o)const
    {return x==o.x&&y==o.y;}
    
    LL val()
    {return (LL)x*y;}
}c[maxn];

point f[maxn][maxn*2];

point dp(point pp)
{
    sx=pp.x;
    sy=pp.y;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            f[i][j]=point(1e9,1e9);
    f[0][m]=point(0,0);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            if(f[i-1][j].x<1e8)
            {
                ten(f[i][j],f[i-1][j]);
                ten(f[i][max(0,j-a[i])],f[i-1][j]+c[i]);
            }
    return f[n][0];
}

void solve(point a,point va,point b,point vb)
{
    ten(ans,va.val());
    ten(ans,vb.val());
    point c,vc;
    c=point(va.y-vb.y,vb.x-va.x);
    vc=dp(c);
    if(vc==va||vc==vb)return;
    solve(a,va,c,vc);
    solve(c,vc,b,vb);
}

int main()
{

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=1LL<<60;
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",a+i,&c[i].x,&c[i].y);
        solve(point(1,0),dp(point(1,0)),point(0,1),dp(point(0,1)));
        printf("%I64d\n",ans);
    }
    return 0;
}