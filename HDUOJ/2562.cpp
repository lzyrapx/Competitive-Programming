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
    cin>>n;
    while(n--)
    {
    	int i;
    	char a[53],t;
    	cin>>a;
    	for(i=0;i<strlen(a);i+=2)
    	{
    		swap(a[i+1],a[i]);
		}
		cout<<a<<endl;
	}
    return 0;
}