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
const LL maxn=1000+10;
const LL mod=10000000; 
char a[12][12]; //坑啊。。。要用char,不能用int 
int main()
{
	int n,m;
	while(cin>>n>>m)
	{   
	    
		for(int i=1;i<=n;i++){
		   for(int j=1;j<=n;j++)
		 {
		 	cin>>a[i][j];
		 }
		}
		 int k=m%4;
		 if(k==0){
		 	for(int i=1;i<=n;i++){
		 		for(int j=1;j<=n;j++){
		 			cout<<a[i][j];
		 		}
		 		cout<<endl;
		 	}
		 }
		 if(k==1||k==-3){
		 	for(int j=1;j<=n;j++)
		 	{
		 		for(int i=n;i>=1;--i)
		 		{
		 			cout<<a[i][j];
		 		}
		 		cout<<endl;
		 	}
		 }
		 if(k==2||k==-2)
		 		{
			 		for(int i=n;i>=1;i--)
			 		{
			 			for(int j=n;j>=1;j--)
			 			{
				 			cout<<a[i][j];
				 		}
				 		cout<<endl;
			 		}
			 	}
			 	if(k==3||k==-1)
			 	{
		 			for(int j=n;j>=1;j--)
		 			{
				 		for(int i=1;i<=n;i++)
				 		{
			 				cout<<a[i][j];
			 			}
			 			cout<<endl;
				 	}
		 	}
	}
	return 0;
	
}