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
    int t,x;
    cin>>t;
    while(t--)
    {
    	cin>>x;
    	LL s=0,i=1;
    	while(s<x)
    	{
    		s+=pow(i,3);
    		i++;
		}
		cout<<i-1<<endl;
	}
    return 0;
}