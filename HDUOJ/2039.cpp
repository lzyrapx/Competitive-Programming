#include<iostream>
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

int main()
{
	int n;
	double a,b,c;
	cin>>n;
	while(n--)
	{
		cin>>a>>b>>c;
		if(((a+b)>c)&&((a+c)>b)&&((b+c)>a))
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}

    return 0;
}
