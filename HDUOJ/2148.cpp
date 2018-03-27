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
const int maxn=3000;
int arr[maxn]={0};
int main()
{
    int t;int mark;
    cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		for(int i=0;i<a;i++)
		{
			cin>>arr[i];
			if(i==b-1)
			 mark=arr[i];
		}
		int sum=0;
		for(int i=0;i<a;i++)
		{
			if(arr[i]>mark)
			sum++;
		}
		printf("%d\n",sum);
	} 
    return 0;
}
