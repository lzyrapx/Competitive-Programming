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
	double h,u,d,f; //f为速度下降的概率，计算出每次速度下降的大小为u*f 
	while(cin>>h>>u>>d>>f){
		if(h==0&&u==0&&d==0&&f==0)break;
		
		 int flag=0;
		double dis=0;
		 int day=1;
		 double s=u*(f/100.0);
		 		 
		while(dis>=0&&dis<=h){
			if(u>0)
			dis+=u;
			if(dis>h){
				flag=1;
				break;
			}
			dis-=d;
			if(dis<0)
			{
				break;
			}
			u-=s;
			day++;
		}
		if(flag)
            cout<<"success on day "<<day<<endl;
        else
            cout<<"failure on day "<<day<<endl;
	}
     return 0;
}