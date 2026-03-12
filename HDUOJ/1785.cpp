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
/*struct node
{
	double x,y;
}a[101];

int cmp(double a,double b)
{
	return a>b;
}
*/ 
int main()
{
	int t;double ans[101];
	double a[101];
	double b[101];
	while(cin>>t)
	{
		if(t<0)break;
		memset(ans,0,sizeof(ans)); 
		for(int i=0;i<t;i++)
		{
			cin>>a[i]>>b[i];
			ans[i]=a[i]/b[i];
		}
		for(int i=0;i<t-1;i++){
			for(int j=i+1;j<t;j++)
			{
				if(ans[j]>ans[i])
				{
					swap(a[i],a[j]);
					swap(b[i],b[j]);
					swap(ans[i],ans[j]);
				}
			}
		}
		if(t>0)printf("%.1f %.1f",a[0],b[0]);
		for(int i=1;i<t;i++)
		{
			printf(" %.1f %.1f",a[i],b[i]);
		}
		cout<<endl;
		/*int maxn=ans[0];
		int mark=0;
		for(int j=1;j<t;j++)
		{
			if(maxn>ans[j])
			   {
			   	maxn=ans[j];
			   	mark=j;
			   }
		}
		printf()*/
	}
    return 0;

}