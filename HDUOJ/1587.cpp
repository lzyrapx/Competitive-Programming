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
	int n,m,i;
	int a[10000];
	while (cin>>n>>m)
	{
		for (i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		cout<<m/a[0]<<endl;
	}
	return 0; 
}