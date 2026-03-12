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
int m[10005];
//n位的二进制数有2^（n-1）个
//s=2^(n-1)(每个的第一位的1)+2^（n-1）*(1/2)*(n-1)(剩下的n-1位每位有一半几率是1，然后乘2^（n-1）个就是总数
int main()
{
  	
	int t,i;
	cin>>t;
	while(t--)
	{
		int n;
		double s;
		cin>>n;
		s=pow(2,n-1)+pow(2,n-1)*(n-1)/2; 
		int ans=s;  //注意转换为int 
		cout<<ans<<endl;
	}
	return 0;
 } 