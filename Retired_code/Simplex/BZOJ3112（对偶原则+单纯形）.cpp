// #include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MX= 10010;
const double eps=1e-6;

/*
接受有n个约束，m个基本变量的方程组a[0~n][0~m]
a[0][]存放需要最大化的目标函数，a[][0]存放常数
返回此线性规划的最小值ans
*/

inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}
// M个限制 N个变量  :a[M][N]
int N,M;
double a[MX  / 10 ][MX];
double b[MX];
double c[MX];
double ans;
/*
注意:ac不了可能是eps的问题
*/
//转轴操作，使矩阵满足方程
// l是替出变量，p是替入变量
inline void pivot(int l,int p) //将第 l 个非基本变量和第 p 个基本变量调换
{
	// std::cout << "l = " << l <<" " <<"p="<< p << '\n';
		b[l]/=a[l][p];
		for(int j=1;j<=M;j++) //改变限制最近的式子的系数
		{
			if(j!=p) a[l][j]/=a[l][p];
		}

    a[l][p] = 1/a[l][p]; //相当于把导入变量与导出变量的系数互换，因为刚开始式子左边的系数为1，所以为原位置系数的倒数

		for(int i=1;i<=N;i++)
		{
			//不是限制最近的式子，替入变量的系数不为0
			if(i!=l&&fabs(a[i][p])>0)
			{

				b[i]-=a[i][p]*b[l]; //相当于把替入变量等于的式子带入含替入变量的式子，改变式子的值
				for(int j=1;j<=M;j++)
				{
						if(j!=p) {
							a[i][j] -= a[i][p] * a[l][j];
					}
				}
				a[i][p]=-a[i][p]*a[l][p];
			}
		}

		ans += c[p] * b[l]; //累计计算当前目标函数常数的值
		// std::cout << "ans" << '\n';
		for(int j = 1; j <= M; j++) if(j != p) c[j] -= c[p] * a[l][j];
		c[p] = -c[p] * a[l][p];

}
double simplex()
{
	int l=0,p=0;
	while(true)  //不断交换
	{
		double mn=1e9;
		for(p = 1; p <= M; p++) {
			if(c[p] > eps) break;
		}
		// std::cout << "p="<< p << '\n';
		if(p==M+1) return ans;
		for(int i=1;i<=N;i++)
		{
			  if(a[i][p] > eps && mn > (b[i] / a[i][p])) mn = b[i] / a[i][p], l = i;
		}
		if(mn == 1e9) {
			return 1e9;
      //puts("Unbounded"); //对于任意的 M，都存在一组解使得目标函数的值大于 M
      //exit(0);
    }
		pivot(l,p); //交换第 l 行，第 p 列
	}
}

//先用对偶原则转换成求对偶问题的解，这样直接转化成了标准型，然后跑Simplex就好了
int main(int argc, char const *argv[]) {

	N = read(), M = read();
	for(int i = 1; i <= N; i++)
	{
		scanf("%lf",&b[i]);
	}
	for(int i = 1; i <= M; i++)
	{
		int s, t;
		// std::cin >> s >> t;
		//scanf("%d%d",&s,&t);
		s = read(), t = read(); scanf("%lf",&c[i]);
		for(int j = s; j <= t; j++)
		{
			a[j][i] = 1; // a[j][i]为 1表示第j个约束中i在[l[j],r[j]]里，可以贡献到和中
		}
	}

	 printf("%d\n",(int)(simplex() + 0.5));
	return 0;
}
