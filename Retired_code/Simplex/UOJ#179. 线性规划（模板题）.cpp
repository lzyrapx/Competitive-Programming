#include<bits/stdc++.h>
using namespace std;
const int MX=110;
/*
注意:ac不了可能是eps的问题
*/
const double eps=1e-8;

// 模板题: http://uoj.ac/problem/179
/*
接受有n个约束，m个基本变量的方程组a[0~n][0~m]
a[0][]存放需要最大化的目标函数，a[][0]存放常数
idn[]存放基本变量的id,初始为1~m
idm[]存放松弛变量的id,初始为m+1~m+n
返回此线性规划的最小值ans
*/
int N,M,t,p;

//要求方案的话，idn[]中的变量值为0, idm[]中的变量值为相应行的[0]
int idn[MX],idm[MX];
double a[MX][MX]； // M个限制 N个变量  :a[M][N]
double res[MX];
double b[MX];

inline void pivot(int l,int p) //将第 l 个非基本变量和第 p 个基本变量调换
{
	swap(idm[l],idn[p]);
	double tmp=-a[l][p];
	a[l][p]=-1;
	for(int i=0;i<=N;i++)
  	{
    	if(fabs(a[l][i])<=eps)a[l][i]=0;
    	else a[l][i]/=tmp;
  	}
  	// 这里可以有随机初始化的黑科技
	for(int i=0;i<=M;i++)
  	{
    	if(i^l)
    	{
      		if(fabs(a[i][p])<=eps) a[i][p]=0;
		  	else
		  	{
			   tmp=a[i][p],a[i][p]=0;
			   for(int j=0;j<=N;j++) a[i][j]+=a[l][j]*tmp;
		  	}
    	}
  	}
}
double simplex()
{
	int l,p;
	double mn,tmp;
	while(true)
	{
		l=M+1,p=N+1;
		idm[l]=idn[p]=N+M+1;
		mn=1e18;
		for(int i=1;i<=N;i++) {
      		if(a[0][i]>eps&&idn[i]<idn[p]) p=i;
    	}
		if(p==N+1)return a[0][0];
		for(int i=1;i<=M;i++)if(a[i][p]<-eps)
		{
			tmp=a[i][0]/-a[i][p];
			if(tmp<mn-eps||tmp<eps+mn&&idm[i]<idm[l])
			l=i,mn=tmp;
		}
		if(l==M+1) {
      		puts("Unbounded"); //对于任意的 M，都存在一组解使得目标函数的值大于 M
      		exit(0);
    	}
		pivot(l,p);
	}
}
double solve()
{
	double tmp=0;
	int p=0;
	for(int i=1;i<=M;i++)
  	{
    	if(a[i][0]<tmp) tmp=a[i][0],p=i;
  	}
	for(int i=1;i<=N;i++)idn[i]=i;
	for(int i=1;i<=M;i++)idm[i]=N+i;
	if(fabs(tmp)<eps) return simplex();
	for(int i=0;i<=N;i++) b[i]=a[0][i],a[0][i]=0;
	idn[++N]=0;
  	a[0][N]=-1;
	for(int i=1;i<=M;i++) a[i][N]=1;
	pivot(p,N);
	if(simplex()<-eps) {
    	puts("Infeasible"); //不存在满足所有约束的解
    	exit(0);
  	}
	for(int i=1;i<=M;i++) if(!idm[i])
	{
		for(int j=1;j<=N;j++) if(fabs(a[i][j])>eps)
		{
			pivot(i,j);
			break;
		}
		break;
	}
	p=0;
	for(int i=1;i<=N;i++) if(!idn[i])p=i;
	for(int i=0;i<=M;i++) swap(a[i][p],a[i][N]);
	swap(idn[p],idn[N]);
  	N--;
	for(int i=1;i<=M;i++)
  	{
    	if(idm[i]<=N){
      		for(int j=0;j<=N;j++)a[0][j]+=a[i][j]*b[idm[i]];
    	}
  	}
	for(int i=1;i<=N;i++)if(idn[i]<=N)a[0][i]+=b[idn[i]];
	return simplex();
}

int main()
{
	scanf("%d%d%d",&N,&M,&t);
	for(int i=1;i<=N;i++) { // 目标函数常数
       scanf("%lf",&a[0][i]);
  	}
  
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++) {
      	scanf("%lf",&a[i][j]); // n个约束，m个基本变量的方程组a[1~m][1~n]
        a[i][j]=-a[i][j];
    }
		scanf("%lf",&a[i][0]); // a[][0]存放不等式右边常数
	}
	printf("%.10lf\n",solve()); // 目标函数最大值
	if(t)
	{
		for(int i=1;i<=M;i++) {
      		if(idm[i]<=N)
      		{
        		res[idm[i]]=a[i][0];
      		}
    	}
		for(int i=1;i<=N;i++) printf("%.10lf ",res[i]);
    	std::cout << '\n';
	}
	return 0;
}
