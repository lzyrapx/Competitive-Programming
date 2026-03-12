#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;
int main()
{
	
	int n;
	cin>>n;
	while(n--){
		int m,i;
		double h,s;
		double maxn=0.00;
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>h;
			maxn=max(maxn,h);
		}
		printf("%.2lf\n",maxn);
	}
    return 0;
}