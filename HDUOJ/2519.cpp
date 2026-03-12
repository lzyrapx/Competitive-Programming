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
   int t,m,n,i,j;
   double a,b;
   cin>>t;
   while(t--)
   {
   	a=1; b=1;
   	cin>>n>>m;
   	for(i=1;i<=m;i++)
   a=a*i; //A(3,3)
   	for(j=n,i=m;i>0;--j,--i)
   	b=b*j; //A(5,3)
   	printf("%.0lf\n",b/a);
   }
	return 0;
 } 