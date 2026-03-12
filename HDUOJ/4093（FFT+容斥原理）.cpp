#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
typedef long long ll;
const long double pi = acos(-1.0);

struct Complex
{
    long double real, image;
    Complex(long double _real, long double _image)
    {
        real = _real;
        image = _image;
    }
    Complex(){}
};

Complex operator + (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c1.image + c2.image);
}

Complex operator - (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real - c2.real, c1.image - c2.image);
}

Complex operator * (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real*c2.real - c1.image*c2.image, c1.real*c2.image + c1.image*c2.real);
}


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
    for(int h=2;h<=len;h<<=1) //分治后计算长度为 h的DFT 
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
            F[i].real/=len;
}
int polynomialLength;//多项式最大长度

void multiply(Complex *p1, Complex *p2)//多项式点值相乘
{
    for(int i = 0; i < polynomialLength; i++)
        p1[i] = p1[i]*p2[i];
    return;
}

void Copy(Complex *p1, Complex *p2)//将p2多项式赋值给p1多项式
{
    for(int i = 0; i < polynomialLength; i++)
        p1[i] = p2[i];
    return;
}

int a[13010];
int p, m;
Complex f[6][1 << 16];
Complex g[7][1 << 16];

const int par[6][10] = //容斥系数
{
    {0},//无效的
    {1},
    {1, -1},
    {1, -3, 2},
    {1, -6, 3, 8, -6},
    {1, -10, 15, 20, -20, -30, 24}
};

void gao()
{
    int maxL = 0;
    for(int i = 1; i <= m; i++)
        maxL = max(maxL, a[i]);
    polynomialLength = 1;
    while(polynomialLength <= maxL*p) polynomialLength <<= 1;

    //初始化f[i]多项式表示i*a[i]数组对应的多项式
    for(int i = 1; i <= p; i++)
    {
        for(int j = 0; j < polynomialLength; j++)
            f[i][j] = Complex(0, 0);
        for(int j = 1; j <= m; j++)
            f[i][i*a[j]].real += 1;
        FFT(f[i], polynomialLength, 1);
    }
    int inclusiveLength = -1;//容斥的等式的长度
    switch(p)
    {
        // p == 1 就是原数列, 答案为 f[1]
        case 1: Copy(g[0], f[1]);
                inclusiveLength = 1;
                break;
        //p == 2 结果是(f[1]^2 - f[2]) / 2
        case 2: Copy(g[0], f[1]);
                multiply(g[0], f[1]);
                Copy(g[1], f[2]);
                inclusiveLength = 2;
                break;
        // p == 3 结果是(f[1]^3 - 3*f[2]*f[1] + 2f[3]) / 6
        case 3: Copy(g[0], f[1]);
                multiply(g[0], f[1]); multiply(g[0], f[1]);
                Copy(g[1], f[2]);
                multiply(g[1], f[1]);
                Copy(g[2], f[3]);
                inclusiveLength = 3;
                break;
        // p == 4 结果是(f[1]^4 - 6*f[2]*f[1]*f[1] + 3*f[2]*f[2] + 8f[3]*f[1] - 6*f[4])/24
        case 4: Copy(g[0], f[1]);
                multiply(g[0], f[1]); multiply(g[0], f[1]); multiply(g[0], f[1]);
                Copy(g[1], f[2]);
                multiply(g[1], f[1]); multiply(g[1], f[1]);
                Copy(g[2], f[2]);
                multiply(g[2], f[2]);
                Copy(g[3], f[3]);
                multiply(g[3], f[1]);
                Copy(g[4], f[4]);
                inclusiveLength = 5;
                break;
        // p == 5 结果是 (f[1]^5 - 10*f[2]f[1]^3 + 15*f[2]*f[2]*f[1] + 20*f[3]*f[1]*f[1] - 20*f[3]*f[2] - 30*f[4]*f[1] + 24*f[5])/120
        case 5: Copy(g[0], f[1]);
                multiply(g[0], f[1]); multiply(g[0], f[1]); multiply(g[0], f[1]); multiply(g[0], f[1]);
                Copy(g[1], f[2]);
                multiply(g[1], f[1]); multiply(g[1], f[1]); multiply(g[1], f[1]);
                Copy(g[2], f[2]);
                multiply(g[2], f[2]); multiply(g[2], f[1]);
                Copy(g[3], f[3]);
                multiply(g[3], f[1]); multiply(g[3], f[1]);
                Copy(g[4], f[3]);
                multiply(g[4], f[2]);
                Copy(g[5], f[4]);
                multiply(g[5], f[1]);
                Copy(g[6], f[5]);
                inclusiveLength = 7;
                break;
    }
    for(int i = 0; i < inclusiveLength; i++)
        FFT(g[i], polynomialLength, -1);
    for(int i = 0; i < polynomialLength; i++)
    {
        double res = 0;
        for(int j = 0; j < inclusiveLength; j++)
            res += g[j][i].real*par[p][j];
        for(int j = 1; j <= p; j++) res /= j;
        if(res > 0.5) printf("%d: %.0f\n", i, res);
    }
    return;
}

int main()
{
     int t;
     int cas=1;
	 scanf("%d", &t);
     while(t--)
    {
        scanf("%d %d", &m, &p);
        for(int i = 1; i <= m; i++)
            scanf("%d", &a[i]);
        printf("Case #%d:\n", cas++);
        gao();
        putchar('\n');
    }
    return 0;
}