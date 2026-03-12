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
	double a,b,c,d;
	  double m,n,ans;
	while(cin>>a>>b>>c>>d){
		m=a-c;
		n=b-d;
		ans=sqrt((a-c)*(a-c)+(b-d)*(b-d));
		printf("%.2lf\n",ans);
	}
	return 0;

}

