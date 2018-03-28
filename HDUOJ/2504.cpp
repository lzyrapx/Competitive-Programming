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
		cin>>a>>b;
		c=b+b;
		while(__gcd(a,c)!=b) 
		{
			c=c+b; //ÈÃcÖð½¥Ôö´ó 
		}
		printf("%d\n",c);
	}
	return 0;
 } 