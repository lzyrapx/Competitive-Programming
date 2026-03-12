#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m=1,i,j;
	int prime(int x);
	while(cin>>n,n>0)
	{
		if(n==1||n==2)
		{
		 cout<<m++<<": no"<<endl;
		 continue;
		}
		if(prime(n))
		cout<<m++<<": yes"<<endl;
		else
		cout<<m++<<": no"<<endl;
	}
	return 0;
}
int prime(int x)
{
	int i;
	double t;
	t=double(x);
	for(i=2;i<=sqrt(t);i++)
	{
		if(x%i==0)
		return 0;
	}
	return 1;
}