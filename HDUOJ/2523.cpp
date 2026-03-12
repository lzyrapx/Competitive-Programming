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
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	int n,k,i,j;
    	cin>>n>>k;
    	int a[2001]={0};
    	int inf[1000];
    	for(i=0;i<n;i++)
    	{
    		cin>>inf[i];
    		for(j=0;j<i;j++)
    		{
    			a[abs(inf[j]-inf[i])]=1;
			}
		}
		for(i=0;k>0;i++)
		{
			if(a[i]==1) --k;
		}
		cout<<i-1<<endl;
	}
    return 0;
}