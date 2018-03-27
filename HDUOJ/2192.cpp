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
int a[10005];
int main()
{
	int t,n;
	int i,max,c,min;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		min=a[0];
		max=1;
		c=1;
		for(i=1;i<n;i++)
		{
			if(min==a[i])
			{
				c++;
			}
			else
			{
				min=a[i];
				c=1;
			}
			if(c>max)
			 max=c;
		}
		cout<<max<<endl;
	}
	return 0;
 } 