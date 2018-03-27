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
    int n,i;
    double sum;
    int flag=1;

    while(scanf("%d",&n)!=EOF)
    {
        if(flag)
        {
              printf("# Cards  Overhang\n");
			  flag=0;
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum=sum+1.0/(2*i);
        }
        printf("%5d     %.3lf\n",n,sum);
    }
    return 0;
}