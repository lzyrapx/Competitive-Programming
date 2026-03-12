#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;

int prime(int n)
{
	if(n<=1) return 0;
	int m=floor(sqrt(n)+0.5); //floor函数: double floor( double arg );
	                        //功能：函数返回参数不大于arg的最大整数
	for(int i=2;i<=m;i++)
	if(n%i==0)
	return 0;
	return 1;
}
int main()
{
	int x,y,n,p,i,f;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		if(x==0&&y==0)break;
	    for( i=x;i<=y;i++)
	  {
		 	n=i*i+i+41;
		  	p=prime(n);
	   	if(p==0)
	   {
	   		printf("Sorry\n");break;
	   }
	     f=i;
	 }
	if(f==y)
	  printf("OK\n");
	 }
	return 0;
}