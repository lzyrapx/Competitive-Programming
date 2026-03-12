#include <bits/stdc++.h>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point3{double x,y,z;};
struct line3{point3 a,b;};
struct plane3{point3 a,b,c;};

//计算dot product U . V
double dmult(point3 u,point3 v)
{
	return u.x*v.x+u.y*v.y+u.z*v.z;
}
//计算cross product U x V
point3 xmult(point3 u,point3 v){
	point3 ret;
	ret.x=u.y*v.z-v.y*u.z;
	ret.y=u.z*v.x-u.x*v.z;
	ret.z=u.x*v.y-u.y*v.x;
	return ret;
}
//矢量差 U - V
point3 subt(point3 u,point3 v){
	point3 ret;
	ret.x=u.x-v.x;
	ret.y=u.y-v.y;
	ret.z=u.z-v.z;
	return ret;
}

//取平面法向量
point3 pvec(point3 s1,point3 s2,point3 s3){
	return xmult(subt(s1,s2),subt(s2,s3));
}

//判四点共面
int dots_onplane(point3 a,point3 b,point3 c,point3 d){
	return zero(dmult(pvec(a,b,c),subt(d,a)));
}

int main()
{
	int t ;
	cin>>t;
	point3 p,pp,ppp,pppp;
	while(t--)
	{
		 cin>>p.x>>p.y>>p.z;
		 cin>>pp.x>>pp.y>>pp.z;
		 cin>>ppp.x>>ppp.y>>ppp.z;
		 cin>>pppp.x>>pppp.y>>pppp.z;
		 int flag=dots_onplane(p,pp,ppp,pppp);
		 if(flag)puts("Yes");
		 else puts("No");
	}
	return 0;
}