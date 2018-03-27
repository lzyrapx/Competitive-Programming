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
    char str[20];
    double m,n,s=0;
    while(scanf("%s%lf%lf",str,&m,&n)!=EOF)
    {
        s+=m*n;
    }
    printf("%.1lf\n",s);
	return 0;	
}