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
int f(long long n){   //判断是否是否是回文数 
	long long d=0,s=n;
	while(s){
		d*=10;
		d+=s%10;
		s/=10;
	}
	if(d==n)
	return 1;
	return 0;
}
int g(long long n){   //计算逆序与原数的和 
	long long s=n,d=0,b;
	while(s){
		d*=10;
		d+=s%10; 
		s/=10;
	}
	b=d+n;
	return b;
}
int main()
{
	int s,a;
	while(cin>>a&&a){
		int i=0,b,c[1000];
		c[0]=a;
		b=a;
		while(f(b)==0){
			c[++i]=g(b);
			b=g(b);
		}
		cout<<i<<endl;
		for(int j=0;j<=i-1;j++)
		cout<<c[j]<<"--->";
		cout<<c[i]<<endl;
	}
}