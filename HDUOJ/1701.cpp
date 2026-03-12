#include<stdio.h>
#include<iostream>
//就是给你两个double的 数据 A B 
// 让你求一个int 数  i  满足  i*A与i*B之间只夹一个数
//也就是题目中的ACMER  而此i既是所求的student ....
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	double 	p,q,a,b;
	int t,i,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%lf%lf",&p,&q);
		for(i=1;;i++)
		{
			a=p*i/100;
			b=q*i/100;
			x=int(a);
			y=int(b);
			if(x<a&&x+1==y)break;
			}
			printf("%d\n",i);
		}

	return 0;
}