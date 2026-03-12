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
int f(int n)
{
	if(n==1)return 4;
	else return (f(n-1)-1)*2;
}
int main() 
{
	int t,n;
	cin>>t;
	while(t--)
	{ 
	    cin>>n;
		int ans;
		ans=f(n);
		cout<<ans<<endl;
	}
	return 0;
} 