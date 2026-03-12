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
	int t; int a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
//当有红球的时候打完红球可以打7分的球，之后7分球由放回桌上,这样一共有8分 
/*重点，根据斯诺克的规则，每次打完红球进后可以打一次彩球，彩球入袋后重新放回桌上，当没有红球时就只能打彩球不过这时彩球不能放回桌上*/
/*所以打进红球后之后打7分球得分最多为8*/
		if(a>6)b=b+(a-6)*8+2+3+4+5+6+7;
		else 
		 for(int i=7;a>0;--i,--a) b+=i;
		 if(b>=c)printf("Yes\n");
		 else printf("No\n");
	}
    return 0;
}