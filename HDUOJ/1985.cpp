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
	double n;
	int t,i;
	char a[3];
	scanf("%d",&t);
	i=1;
	while(t--)
	{
		scanf("%lf %s",&n,a);
		if(strcmp(a,"kg")==0)
			printf("%d %.4lf lb\n",i,n*2.2046);
		else if(strcmp(a,"lb")==0)
			printf("%d %.4lf kg\n",i,n*0.4536);
	    else if(strcmp(a,"l")==0)
			printf("%d %.4lf g\n",i,n*0.2642);
		else if(strcmp(a,"g")==0)
			printf("%d %.4lf l\n",i,n*3.7854);
		i++;
	}
	return 0;
} 