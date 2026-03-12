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

int main()
{
	int a,b,c,m,n,i=1,p=-1;
	double sum=0;
	cin>>m;
	while(m--)
	{	
	    i=1;p=-1;
		sum=0;
		cin>>n;
		while(n--)
		{
		  p*=-1;
		sum+=(1.0/i)*p;
		  i++;
		
		}
		//cout<<fixed<<setprecision(2)<<sum<<endl;
		printf("%.2lf\n",sum);
	}
	return 0;
}

