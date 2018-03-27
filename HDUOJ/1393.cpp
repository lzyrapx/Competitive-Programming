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
    int s,d;
    while(cin>>s>>d)
    {
        if(s==0&&d==0)break;
		int i=0;
        while(s%60)
        {
            s+=(d*s)%60;  //È¥µô%60¾Í»áWA 
            i++;
            if(i>10000)
                break;
        }
        if(i<=10000)
            cout<<i<<endl;
        else
            cout<<"Impossible"<<endl;	
    }
	return 0;	
}