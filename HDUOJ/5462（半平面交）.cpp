#pragma comment(linker, STACK102400000,102400000)
#includebitsstdc++.h
#include stdio.h
#include string.h
#include algorithm
#include iostream
#include cstring
#include vector
#include map
#include cmath
#include queue
#include set
#include bitset
#include iomanip
#include list
#include stack
#include utility 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pairint,int pii;
typedef vectorint vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL32);
const int N =110; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen(in.txt,r,stdin) 
#define rep(i,j,k) for (int i = j; i = k; i++)  
#define per(i,j,k) for (int i = j; i = k; i--)  
#define lson x  1, l, mid  
#define rson x  1  1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
const int lowbit(int x) { return ((x)&((x)^((x)-1))); } 
int read(){ int v = 0, f = 1;char c =getchar();
while( c  48  57  c ){if(c=='-') f = -1;c = getchar();}
while(48 = c && c = 57) v = v10+c-48, c = getchar();
return vf;}
struct Point
{
    double x,y;
    Point(double x=0,double y=0)x(x),y(y){}
};

typedef Point Vector;

Vector operator+(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator-(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator(Vector a,double p){return Vector(a.xp,a.yp);}
double Dot(Vector a,Vector b){return a.xb.x+a.yb.y;}
double Cross(Vector a,Vector b){return a.xb.y-a.yb.x;}
double Length(Vector a){return sqrt(Dot(a,a));}
Vector Normal(Vector a){double L=Length(a);return Vector(-a.yL,a.xL);}

double PolygonArea(vectorPointp)
{
    int n=p.size();
    double area=0;
    for(int i=1;in-1;i++)
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area2;
}

struct Line
{
    Point p;
    Vector v;
    double ang;
    Line(){}
    Line(Point p,Vector v)p(p),v(v){ang=atan2(v.y,v.x);}
    bool operator(const Line&L)const
    {
        return angL.ang;
    }
};

bool OnLeft(Line L,Point p)
{
    return Cross(L.v,p-L.p)0;
}

Point GetLineIntersection(Line a,Line b)
{
    Vector u=a.p-b.p;
    double t=Cross(b.v,u)Cross(a.v,b.v);
    return a.p+a.vt;
}

vectorPoint HalfplaneIntersection(vectorLineL)
{
    int n=L.size();
    sort(L.begin(),L.end());

    int first,last;
    vectorPoint p(n);
    vectorLine q(n);
    vectorPoint ans;

    q[first=last=0]=L[0];
    for(int i=1;in;i++)
    {
        while(firstlast&&!OnLeft(L[i],p[last-1]))last--;
        while(firstlast&&!OnLeft(L[i],p[first]))first++;
        q[++last]=L[i];
        if(fabs(Cross(q[last].v,q[last-1].v))eps)
        {
            last--;
            if(OnLeft(q[last],L[i].p))q[last]=L[i];
        }
        if(firstlast)p[last-1]=GetLineIntersection(q[last-1],q[last]);
    }
    while(firstlast&&!OnLeft(q[first],p[last-1]))last--;
    if(last-first=1)return ans;
    p[last]=GetLineIntersection(q[last],q[first]);

    for(int i=first;i=last;i++)ans.push_back(p[i]);
    return ans;
}

vectorPointp,poly;

Point person[N][2020];
Point sum[N];
Point sum2[N];
double ans[N];
int main()
{
    int T;
    int rnd=0;
    scanf(%d,&T);
    while(T--)
    {
        int n,m;
        scanf(%d%d,&n,&m);
        for(int i=0;in;i++)
        for(int j=0;jm;j++)
            scanf(%lf%lf,&person[i][j].x,&person[i][j].y);
        memset(sum,0,sizeof(sum));
        memset(sum2,0,sizeof(sum2));
        for(int i=0;in;i++)
        for(int j=0;jm;j++)
        {
            sum[i].x+=person[i][j].x;
            sum[i].y+=person[i][j].y;
            sum2[i].x+=person[i][j].xperson[i][j].x;
            sum2[i].y+=person[i][j].yperson[i][j].y;
        }
        for(int i=0;in;i++)
        {
            vectorLineL;
            for(int j=0;jn;j++)
                if(j!=i)
              {
                double a=2(sum[i].x-sum[j].x);
                double b=2(sum[i].y-sum[j].y);
                double c=sum2[j].x+sum2[j].y-sum2[i].x-sum2[i].y;
                Point p;
                if(fabs(a)fabs(b))p=Point(-ca,0);
                else p=Point(0,-cb);
                Vector v(b,-a);
                L.push_back(Line(p,v));
             }
            L.push_back(Line(Point(0,0),Vector(0,-1)));
            L.push_back(Line(Point(4095,0),Vector(0,1)));
            L.push_back(Line(Point(0,0),Vector(1,0)));
            L.push_back(Line(Point(4095,4095),Vector(-1,0)));
            vectorPointch=HalfplaneIntersection(L);
            ans[i]=fabs(PolygonArea(ch));
        }
        printf(Case #%d,++rnd);
        for(int i=0;in;i++)
            printf( %.0lf,ans[i]);
        puts();
    }
}