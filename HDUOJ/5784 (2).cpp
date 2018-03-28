#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2010;
struct Point
{
    LL x,y;
    Point(){}
    Point(LL _x,LL _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    LL operator * (const Point &t)const  // 叉积 : 有向面积
    {
        return x*t.y-y*t.x;
    }
    LL operator ^ (const Point &t)const  // 点积 : 有向长度
    {
        return x*t.x+y*t.y;
    }
    bool operator < (const Point &t)const  // 极角排序
    {
        bool up[2]={0,0};
        if( y>0 || (y==0 && x>0))up[0]=1;
        if(t.y>0 || (t.y==0 && t.x>0))up[1]=1;
        if(up[0]^up[1])return up[0];
        return (*this)*t ? (*this)*t>0 : ((*this)^(*this))<(t^t);
    }
}p[MAXN],v[MAXN<<1];
/*
/* 
三角形总共有C(n,3)个,对应的锐角钝角直角总和为3*C(n,3) 
假设有x个钝角,y个直角  钝角和直角分别对应两个锐角 
那么锐角三角形的数量为：(3*C(n,3)-2*x-x-2*y-y)/3 = C(n,3)-x-y 
统计有多少个钝角和直角! 
*/  
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%I64d%I64d",&p[i].x,&p[i].y);
        LL res=1LL*n*(n-1)*(n-2)/6,tmp=0;
        for(int c=0;c<n;c++)
        {
            int tot=0;
            for(int i=0;i<n;i++)
            {
                if(c==i)continue;
                v[tot++]=p[i]-p[c];   // 向量i->j
            }
            sort(v,v+tot);
            for(int i=0;i<tot;i++)
                v[i+tot]=v[i];
            LL cnt=0;
            for(int i=0;i<tot;i++)
            {
                if(i && v[i-1]*v[i]==0 && (v[i-1]^v[i])>0) cnt++;  //两条向量共线且同向->三点共线
                else cnt=0;
                tmp+=cnt;
            }
            for(int i=0,p1=0,p2=0;i<tot;i++)
            {
                while(p1<=i || (p1<i+tot && v[p1]*v[i]<0 && (v[p1]^v[i])>0))p1++; // v[j]左边的锐角个数 
                while(p2<=i || (p2<i+tot && v[p2]*v[i]<0))p2++; // v[j]左边的锐角+钝角+直角个数 
                res-=p2-p1;
            }
        }
        printf("%I64d\n",res-tmp/2);
    }
    return 0;
}