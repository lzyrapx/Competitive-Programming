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
int f(int y)
{
	return y%400==0||y%100!=0&&y%4==0;
}
int main()
{
	int i,y,m,d;
	int t[2][31]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	char date[8][30]={{"Sunday"},{"Monday"},{"Tuesday"},{"Wednesday"},{"Thursday"},{"Friday"},{"Saturday"}};
	while(cin>>y>>m>>d)
	{
		if(!f(y)&&m==2&&d>28||y==0||m==0||d==0||d>t[f(y)][m]||m>12)
		{
			printf("illegal\n");
		}
		else
		{
			for(i=1;i<y;i++)
			  d+=365+f(i); 
			  for(i=1;i<m;i++)
			  d+=t[f(y)][i];
			  d%=7;
			  printf("%s\n",date[d]);
		}
	}
    return 0;

}