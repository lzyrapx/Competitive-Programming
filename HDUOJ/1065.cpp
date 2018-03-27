#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int t;int times=0;
    scanf("%d",&t);
    while(t--)
    {
    	double x,y; 	double res=0;	
    	cin>>x>>y;
       res=(x*x+y*y)*(3.1415926)/100;
    	printf("Property %d: This property will begin eroding in year %d.\n",++times,int(res+1));
	}
	puts("END OF OUTPUT.");
	return 0;
}