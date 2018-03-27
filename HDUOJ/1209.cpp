#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

struct TIME
{
	int h,m;
	double angle;
	int time;
};TIME clock[1000];

bool cmp(TIME a,TIME b)
{
	if(a.angle==b.angle) return a.time<b.time;
	else return a.angle<b.angle;
}

int main()
{
	int n;
    scanf("%d",&n);
  	while(n--)
	{
		int i;
		
		for(i=0;i<5;i++)
		{
		    scanf("%d:%d",&clock[i].h,&clock[i].m);
		    
		    clock[i].angle=fabs( (clock[i].h%12)*30+clock[i].m*0.5-clock[i].m*6 );//时针每小时走30度，每分钟走0.5,分针每分钟走6度
		    
		    if(clock[i].angle>180)
			clock[i].angle=360-clock[i].angle;
			
		    clock[i].time=60*clock[i].h+clock[i].m; //若夹角相等则按时间早到晚
	    }
		
		sort(clock,clock+5,cmp);
		
		printf("%02d:%02d\n",clock[2].h,clock[2].m);
	}
	return 0;
}