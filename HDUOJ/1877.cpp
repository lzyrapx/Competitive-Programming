#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;
int main() 
{
	int m,a,b;
	int arr[10000]={0};
	while(cin>>m>>a>>b)
	{
		int c=a+b;
		int i=0;
		if(c==0)printf("0\n");
		else{
			while(c>0)
		{
			arr[i++]=c%m;
			c=c/m;
		} 
		for(int j=i-1;j>=0;--j)
		{
			cout<<arr[j]; 
		}
		cout<<endl;
		}
		
	} 
	return 0;
} 