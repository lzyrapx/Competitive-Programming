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
#include<queue>
#include<algorithm>  
typedef long long LL;  
using namespace std; 

int main()
{
   
   int n;
   int a,m;
   cin>>n;
   while(n--)
   {
   	cin>>a>>m;
   	int sum=0;
   	for(int i=0;i<m;i++)
   	{
   		for(int j=0;j<=m/2;j++)
   		{
   			for(int k=0;k<=m/5;k++)
   			{
   				if((i+2*j+5*k)==m&&i+j+k==a)
                    sum++;
			   }
		   }
	   }
	   cout<<sum<<endl;
   }
    return 0;
}