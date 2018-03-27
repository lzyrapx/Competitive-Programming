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
	int a,b,c,t,n;
	
	cin>>t;
	while(t--)
	{
		int A=0,B=0,C=0;
	
		cin>>n;
		a=n/2;
		b=((n-a)*2)/3;
		c=n-a-b;
		if(a%10==0) A=a/10;
		else A=a/10+1;
		if(b%10==0)B=b/10;
		else B=b/10+1;
		if(c%10==0)C=c/10;
		else C=c/10+1;
		printf("%d\n",A+B+C);
	}
	return 0;
 } 