#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;
int sum(int n,int k)
{
	int s=0;
	while(n!=0)
	{
		s+=n%k;
		n/=k;
	}
	return s;
}
int main()
{
	int n;
	while(cin>>n,n)
	{
		int a,b,c;
		a=sum(n,10);  //每个数位上的数相加即可，不用化成其他进制
		b=sum(n,12);
		c=sum(n,16);
		if(a==b&&b==c&&a==c)
		cout<<n<<" is a Sky Number."<<endl;
		else
			cout<<n<<" is not a Sky Number."<<endl;
	}
	return 0;
}