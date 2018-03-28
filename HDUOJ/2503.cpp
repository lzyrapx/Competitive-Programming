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
#include<algorithm>  
typedef long long LL;  
using namespace std; 
const int maxn=100;

int main()
{
  	
	int a,b,c,d,e,f,m,flag;
	cin>>m;
	while(m--)
	{
		flag=0;
		cin>>a>>b>>c>>d;
		f=b*d;
		e=a*d+b*c;
		while(flag!=1)
		{
			flag=__gcd(e,f);
			e/=flag;
			f/=flag;
		}
		printf("%d %d\n",e,f);
	}
	return 0;
 } 