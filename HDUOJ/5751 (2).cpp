#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
#define lson  l , mid , rt << 1  
#define rson  mid + 1 , r , rt << 1 | 1  

const int N = 6e5+10;
const double pi = acos(-1.0);
const int mod=313; 
char s1[N],s2[N];
int len,res[N];

struct Complex
{
    double r,i;
    Complex(double r=0,double i=0):r(r),i(i) {};
    Complex operator+(const Complex &rhs)
    {
        return Complex(r + rhs.r,i + rhs.i);
    }
    Complex operator-(const Complex &rhs)
    {
        return Complex(r - rhs.r,i - rhs.i);
    }
    Complex operator*(const Complex &rhs)
    {
        return Complex(r*rhs.r - i*rhs.i,i*rhs.r + r*rhs.i);
    }
} va[N],vb[N];

//雷德算法--倒位序  
void rader(Complex F[],int len) //len = 2^M,reverse F[i] with  F[j] j为i二进制反转
{
    int j = len >> 1;
    for(int i = 1;i < len - 1;++i)
    {
        if(i < j) swap(F[i],F[j]);  // reverse
        int k = len>>1;
        while(j>=k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}
//FFT实现
void FFT(Complex F[],int len,int t)
{
    rader(F,len);
    for(int h=2;h<=len;h<<=1) //分治后计算长度为h的DFT 
    {
        Complex wn(cos(-t*2*pi/h),sin(-t*2*pi/h)); //单位复根e^(2*PI/m)用欧拉公式展开
        for(int j=0;j<len;j+=h)
        {
            Complex E(1,0); //旋转因子
            for(int k=j;k<j+h/2;++k)
            {
                Complex u = F[k];
                Complex v = E*F[k+h/2];
                F[k] = u+v; //蝴蝶合并操作
                F[k+h/2] = u-v;
                E=E*wn; //更新旋转因子
            }
        }
    }
    if(t==-1)   //IDFT
        for(int i=0;i<len;++i)
            F[i].r/=len;
}

//求卷积 
void Conv(Complex a[],Complex b[],int len) 
{
    FFT(a,len,1);
    FFT(b,len,1);
    for(int i=0;i<len;i++) b[i] = a[i]*b[i];
    FFT(b,len,-1);
}

ll ans[N];
int n;
int mx[1<<18];
vector<int> p[N];
int a[N];
Complex x[1<<18],y[1<<18];

void build(int l, int r, int rt)
{
	if(l==r)
	{
		mx[rt]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(lson);
	build(rson);
	mx[rt]=max( mx[rt<<1], mx[rt<<1|1] );
}

int getmax(int l, int r, int rt, int L, int R)  
{  
    if (l >= L &&r <= R) return mx[rt];  
    int mid = (l + r) >> 1;  
    int ret = 0;  
    if (L <= mid) ret=max(ret, getmax(lson, L, R));  
    if (R > mid)  ret=max(ret, getmax(rson, L, R));  
    return ret;  
}  

void gao(int l,int r)  
{  
	if (l > r)return;  
    if (l == r)  
    {  
        ans[1]++;  
        return;  
    }  
    int v = getmax(1, n, 1, l, r);  
    
    int left = lower_bound(p[v].begin(), p[v].end(), l) - p[v].begin();  
    int right = upper_bound(p[v].begin(), p[v].end(), r) - p[v].begin() - 1;  
    
    vector<int> pos;  
    
    pos.push_back(l - 1);  
    for (int i = left; i <= right; i++)
		pos.push_back(p[v][i]);  
		
    pos.push_back(r + 1);  
    
    int num = right - left + 2;  
    for (int i = 0; i < num; i++)
    {
    	x[i] =  Complex( pos[i + 1] - pos[i], 0 ); 
	}
	 
    for (int i = 0; i < num; i++)
	{
		y[i] = x[num - 1 - i];
	}  
    int len = 1; 
	while (len < num + num) len<<= 1;
	  
    for (int i = num; i < len; i++)
	{
		x[i] = y[i] = Complex(0,0);  
	}
    Conv(x,y,len);
    
    for (int i = 0; i < num - 1; i++)
	{
		ans[num - 1 - i] += ( y[i].r + 0.5); 
	} 
    for (int i = 0; i < num; i++)  
    {  
        gao(pos[i] + 1, pos[i + 1] - 1);  
    }  
}  
void solve()  
{  
	int t;
    scanf("%d", &t);  
    while(t--)
    {
        scanf("%d", &n);  
        for (int i = 1; i <= n;i++)  
        {  
            p[i].clear();  
            ans[i] = 0;  
        }  
        for (int i = 1; i <= n; ++i)  
        {  
            scanf("%d", &a[i]);  
            p[a[i]].push_back(i);  
        }  
        build(1,n,1);  
        gao(1, n);  
        ll ANS = 0;  
        for (int i = 1; i <= n; ++i)
		{
			ANS += ans[i] ^ i;
		} 
		  
        printf("%lld\n", ANS);  
    }
}  

int main()
{
    solve();
    return 0;
}
