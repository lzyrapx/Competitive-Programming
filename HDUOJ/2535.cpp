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
    int n; int a;
    while(cin>>n,n)
    {
    	int s[1002];
    	for(int i=0;i<n;i++)
    	{
    		cin>>a;
    		s[i]=a/2+1;
		}
		sort(s,s+n);
		int ans=0;
		for(int i=0;i<n/2+1;i++)
		 ans+=s[i];
		 cout<<ans<<endl;
	}
    return 0;
}