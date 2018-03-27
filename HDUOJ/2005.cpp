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

int main()
{
	int y,m,d;
	while(~scanf("%d/%d/%d",&y,&m,&d))
	{
		int k,leap;
 		int day[2][13]={
	 {0,31,28,31,30,31,30,31,31,30,31,30,31},
	 {0,31,29,31,30,31,30,31,31,30,31,30,31}
	 };
	 leap=(y%4==0&&y%100!=0||y%400==0);
	 for(k=1;k<m;k++)
	 {
	 	  d=d+day[leap][k];
	 }
	 printf("%d\n",d);

	}

	return 0;

}

