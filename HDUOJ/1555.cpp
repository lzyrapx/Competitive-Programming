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
	int m,k;
	while(cin>>m>>k,m&&k)
	{
		int day=0;int j=0;
		while(m>0)
		{
			day++;
			m=m-1;
			j++;
			if(j==k) m=m+1,j=0;
		}
		cout<<day<<endl; 
	}
	return 0;

}