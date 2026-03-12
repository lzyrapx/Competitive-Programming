#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI=acos(-1.0);
const int Maxn=(1<<18)+10;
struct Complex
{
    double x,y;
    Complex(double x_=0,double y_=0)
    {
        x=x_;
        y=y_;
    }
    Complex operator -(const Complex &t)const
    {
        return Complex(x-t.x,y-t.y);
    }
    Complex operator +(const Complex &t)const
    {
        return Complex(x+t.x,y+t.y);
    }
    Complex operator *(const Complex &t)const
    {
        return Complex(x*t.x-y*t.y,x*t.y+y*t.x);
    }
    void clear()
    {
        x=0;y=0;
    }
} x1[Maxn],x2[Maxn];
void rader(Complex y[],int len)
{
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++)
    {
        if(i<j) swap(y[i],y[j]);
        k=len/2;
        while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k) j+=k;
    }
}
void fft(Complex y[],int len,int on)
{
    rader(y,len);
    for(int h=2;h<=len;h<<=1)
    {
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j=0;j<len;j+=h)
        {
            Complex w(1,0);
            for(int k=j;k<j+h/2;k++)
            {
                Complex u=y[k];
                Complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)
        for(int i=0;i<len;i++)
            y[i].x/=len;
}
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    int len=1;
    while(len<max(n,m)*2) len<<=1;
    for(int i=0;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        x1[i].x=x;
    }
    for(int i=0;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        x2[i].x=x;
    }
    fft(x1,len,1);
    fft(x2,len,1);
    for(int i=0;i<=len;i++)
        x1[i]=x1[i]*x2[i];
    fft(x1,len,-1);
    for(int i=0;i<=n+m;i++)
    {
        if(i) printf(" ");
        printf("%d",(int)(x1[i].x+0.5));
    }
    puts("");
}
