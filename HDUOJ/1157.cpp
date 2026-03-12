#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	
	int n,a[100010];
	while(cin>>n){
	for(int i=0;i<n;i++)
	  cin>>a[i];
	sort(a,a+n);
	cout<<a[n/2]<<endl;	
    }
   return 0;
}
