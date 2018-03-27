#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;
#define PI 3.1415927
int main()
{
	double r;
	double ans;
	while(cin>>r){
		ans=(4*PI*r*r*r)/3;
		printf("%.3lf\n",ans);
	}
	return 0;

}

