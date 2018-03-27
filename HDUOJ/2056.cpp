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
	
	double x1,y1,x2,y2,x3,y3,x4,y4;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
	//保证左边是右下角，右边的数是左上角 (画个图吧...)
		if(x1>x2)swap(x1,x2); 
		if(y1>y2)swap(y1,y2);
		
		if(x3>x4)swap(x3,x4);
		if(y3>y4)swap(y3,y4);
    //画个图就知道是什么意思了 
		x1=max(x1,x3);
		y1=max(y1,y3);
		x2=min(x2,x4);
		y2=min(y2,y4);
		printf("%.2lf\n",x1>x2||y1>y2? 0:(x2-x1)*(y2-y1));//注意重合的情况 
	}
    return 0;
}