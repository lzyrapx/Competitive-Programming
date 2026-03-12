#include<stdio.h>
#include<iostream>
typedef long long LL;
using namespace std;
//先分解质因数:
//如果一个数分解质因数的形式是：M = 2^a * 3^b * 5^c * 7^d 
//则M的约数个数 = (a+1)(b+1)(c+1)(d+1)
int main()
{
     LL n;
     LL a[4];
     while(cin>>n,n)
     {
     	for(a[0]=0;n%2==0; n/=2)
     	{
     		a[0]++;
		}
	   for(a[1]=0; n%3==0; n/=3)
	   {
	   	 a[1]++;
	   }    
	   for(a[2]=0;n%5==0;n/=5)
	   {
	   	a[2]++;
	   }
	   for(a[3]=0; n%7==0;n/=7)
	   {
	   	a[3]++;
	   }
	   int sum=(a[0]+1)*(a[1]+1)*(a[2]+1)*(a[3]+1);
	   cout<<sum<<endl; 
	 }
     
	return 0;
}