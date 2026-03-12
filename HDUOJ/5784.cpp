#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
/*
直接统计锐角三角形较困难，考虑问题的反面，统计直角三角形、钝角三角形、平角三角形。
首先枚举三角形的一个端点A，对其他点进行象限为第一关键字，极角为第二关键字排序。
然后使用三个指针，进行O（n）的扫描。
具体做法为用 i 指针指向三角形的第二个端点B。
我们可以假想通过平移和旋转，把A点置于平面直角坐标系的原点，把B点置于x轴的正方向。
那么可以与AB组成钝角或直角的点就在三四象限或者y轴。
将 j 指针指向第一象限内可以组成锐角的最靠后的点，
将k指针从j + 1 开始扫描至最后一个可以组成钝角的点，然后统计对答案的贡献。
之后将 i 指针 +1，继续扫描。
*/
const double eps=1e-8;
struct Point{
    ll x,y;
    int f;//代表在哪一个象限
    friend Point operator-(Point aa,Point bb){
        return (Point){aa.x-bb.x,aa.y-bb.y};
    }
}a[2005],b[2005];
Point S;
int n,m;
//叉积 
inline ll cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
inline int cal(Point a)//计算象限
{
    if(a.x>0&&a.y==0) return 1;
    if(a.x>0&&a.y>0) return 1;
    if(a.x==0&&a.y>0) return 2;
    if(a.x<0&&a.y>0) return 2;
    if(a.x<0&&a.y==0) return 3;
    if(a.x<0&&a.y<0) return 3;
    if(a.x==0&&a.y<0) return 4;
    if(a.x>0&&a.y<0) return 4;
}
inline bool cmp(const Point a,const Point b)//先按象限排序，再按极角排序
{
    if(a.f<b.f) return true;
    if(a.f>b.f) return false;
    ll temp=cross(S,a,b);//用了叉积来极角排序 
    if(temp>0) return true;
    else return false;
}
inline bool ok(Point a,Point b,Point c)
{
    ll temp=(b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
    if(temp>0) return true;
    else return false;
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++){
            scanf("%I64d%I64d",&a[i].x,&a[i].y);
        }
        ll sum=0;//统计除了锐角三角形的其他三角形的个数
        for(int p=1; p<=n; p++)//枚举三角形的一个顶点
        {
            S=a[p];
            m=0;
            for(int j=1; j<=n; j++){
                if(j!=p) b[++m]=a[j];
            }
            for(int i=1; i<=m; i++) b[i].f=cal(b[i]-S);
            sort(b+1,b+m+1,cmp);//极角排序
            //two pointers
            int i=1,j=1,k=1;
            while(ok(S,b[i],b[j])&&cross(S,b[i],b[j])>=0&&j<=m) j++;
            if(j==m+1) continue;
            j--;k=j+1;
            while(i<=m){
                if(!ok(S,b[i],b[k])){
                    while(!ok(S,b[i],b[k+1])&&k<m) k++;
                    sum+=k-j;
                }
                i++;
                if(j<i) j=i;
                while(ok(S,b[i],b[j+1])&&cross(S,b[i],b[j+1])>0&&j<m) j++;
                if(k<=j) k=j+1;
                if(k>m) break;
            }
        }
        ll ans=1ll*n*(n-1)*(n-2)/6;
        ans-=sum;
        //cout<<ans<<" "<<sum<<endl;
        printf("%I64d\n",ans);
    }
}
