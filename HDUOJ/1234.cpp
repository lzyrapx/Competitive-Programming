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
#define MAX 3600*24

int f(int h,int m,int s){
	
	return h*3600+m*60+s;
}

int main()
{
	int h1,m1,s1,num[1000][17],h2,m2,s2;
    int i,j,t,n,flag1,flag2;
	scanf("%d",&t);
	while(t--)
	{
		int max=0,min=MAX,sum1=0,sum2=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		   scanf("%s %d:%d:%d %d:%d:%d",num[i],&h1,&m1,&s1,&h2,&m2,&s2);
		   sum1=f(h1,m1,s1);
		   if(min>=sum1)    //最早签到时间 
		   {
			   min=sum1;
			   flag1=i;
		   }
		   sum2=f(h2,m2,s2);
		   if(max<=sum2)  //最晚签离时间 
		   {
			   max=sum2;
			   flag2=i;
		   }
		}
		printf("%s %s\n",num[flag1],num[flag2]);
	}

	return 0;
}


