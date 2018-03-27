#include <bits/stdc++.h>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point
{
    double x,y;
};
struct line
{
    point a,b;
};


//叉积
double multi(point p0, point p1, point p2)
{
    return ( p1.x - p0.x )*( p2.y - p0.y )-( p2.x - p0.x )*( p1.y - p0.y );
}
//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double xmult(double x1,double y1,double x2,double y2,double x0,double y0)
{
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

//判三点是否共线
int dots_inline(point p1,point p2,point p3)
{
    return zero(xmult(p1,p2,p3));
}


//相交返回true,否则为false, 接口为两线段的端点
bool isIntersected(point s1,point e1, point s2,point e2)
{
    return  (max(s1.x,e1.x) >= min(s2.x,e2.x))  &&
            (max(s2.x,e2.x) >= min(s1.x,e1.x))  &&
            (max(s1.y,e1.y) >= min(s2.y,e2.y))  &&
            (max(s2.y,e2.y) >= min(s1.y,e1.y))  &&
            (multi(s1,s2,e1)*multi(s1,e1,e2)>0) &&
            (multi(s2,s1,e2)*multi(s2,e2,e1)>0);
}
//判点是否在线段上,包括端点（下面为两种接口模式）
int dot_online_in(point p,line l)
{
    return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
//判两点在线段异侧,点在线段上返回0
int opposite_side(point p1,point p2,line l)
{
    return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)<-eps;
}
//判两点在线段同侧,点在线段上返回0
int same_side(point p1,point p2,line l)
{
    return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
//判两线段相交,包括端点和部分重合
int intersect_in(line u,line v)
{
    if (!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
        return !same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
    return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}

//判两线段相交,不包括端点和部分重合
int intersect_ex(line u,line v)
{
    return opposite_side(u.a,u.b,v)&&opposite_side(v.a,v.b,u);
}

int main()
{
	int t;
	cin>>t;
	line u,v;
	while(t--)
	{
		cin>>u.a.x>>u.a.y>>u.b.x>>u.b.y;
		cin>>v.a.x>>v.a.y>>v.b.x>>v.b.y;
		int flag=intersect_in(u,v);
		if(flag)puts("Yes");
		else puts("No");
	}
	return 0;
}