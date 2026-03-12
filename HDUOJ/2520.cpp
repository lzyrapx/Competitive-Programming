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
   LL t,a,b;
   LL n;
   cin>>t;
   while(t--)
   {
   	
   	cin>>n;
   	LL sum=0;
   	for(LL i=1;i<=n;i++)
   	{
   		a=1+2*(i-1);
   		sum=(sum+a)%10000;
	   }
	   printf("%lld\n",sum);
   }
	return 0;
 } 