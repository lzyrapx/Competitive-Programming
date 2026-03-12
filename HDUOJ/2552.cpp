/*
1.tan(a+b) = ( tan(a) + tan(b) ) / (1 – tan(a) * tan(b) )

2.tan( arctan(x) ) = x
arctan(1/s) = arctan(1/u)+arctan(1/v)

所以得1/s = tan( arctan(1/u)+arctan(1/v) ) = (tan(arctan(1/u)) + tan(arctan(1/v)))/(1-tan(arctan(1/u))*tan(arctan(1/v))) = (1/u + 1/v) / (1 - 1/(uv))

所以解得 uv = 1 + us + vs
所以v*u-s*u-s*v恒等于1
*/ 
#include<iostream>
using namespace std;
int main()
{
	int t;
	double s,u,v;
	cin>>t;
	while(t--)
	{
		cin>>s>>u;
		cout<<1<<endl;
	}
	return 0; 
}


------------------

#include<iostream>     
#include<cstdlib>    
#include<cstdio>    
#include<cmath>    
#include<cstring>    
#include<string>    
#include<cstdlib>    
#include<iomanip>    
#include<vector>    
#include<list>    
#include<map>    
#include<queue>  
#include<algorithm>    
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		double s,u;
		scanf("%lf%lf",&s,&u);
		double v=1.0/tan(atan(1/s)-atan(1/u));
		printf("%.0lf\n",(v*u-s*u-s*v));
	}
	return 0;
}