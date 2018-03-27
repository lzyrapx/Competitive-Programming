#include<iostream>  
#include<memory.h>  
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
const LL maxn=1e6;
const LL mod=10000000; 
int a[maxn]={0};
//素数筛选：打表 
int main()
{
	
	int n,k=1;
	for(int i=2;i<maxn;i++)
	{
		if(a[i]==0)
		{
			a[i]=k++; //position 
			for(int j=i+i;j<maxn;j+=i)
			{
				a[j]=a[i]; 
			}
		}
	}
	while(~scanf("%d",&n))
	{
		if(n==1)printf("0\n"); 
		else
		cout<<a[n]<<endl;
	}
    return 0;	
}