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
const int maxn=1000000000;
char a[maxn];
int main()
{
	 LL t,x,m,k,c;	
	 int flag=0;
	scanf("%lld",&t);
	while(t--)
	{
		 LL num;
		scanf("%lld %lld %lld %lld",&x,&m,&k,&c);
	     num=m%k;
		LL ans=0;
		for(int i=1;i<=num;i++)
		{
			ans=(ans*10+x)%k;
		}
	//	cout<<num<<endl;
		if(ans%k==c)
		printf("Case #%lld:\nYes\n",++flag);
		else
		printf("Case #%lld:\nNo\n",++flag);
		
		 
	}
	return 0;
 } 