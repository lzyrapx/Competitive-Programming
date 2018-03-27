#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	int n,m;
	while(cin>>n>>m){
		printf("%d\n",n*m/gcd(n,m));
	}
   return 0;
}
